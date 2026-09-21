#ifndef DETAIL_XTE_HEADER_MATH_SERIALIZE
#	define DETAIL_XTE_HEADER_MATH_SERIALIZE
#
#	include "../abs.hpp"
#	include "../aliases.hpp"
#	include "../arithmetic.hpp"
#	include "../array.hpp"
#	include "../approx_equal.hpp"
#	include "../compare.hpp"
#	include "../make.hpp"
#	include "../math/sign_cast.hpp"
#	include "../math/float.hpp"
#	include "../math/sign.hpp"
#	include "../string.hpp"
#	include "../string_view.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_signed_int.hpp"
#	include <algorithm>
#	include <ranges>

namespace xte {
	struct serialize_config {
		xte::string_view digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
		xte::string_view minus = "-";
		xte::string_view plus = "+";
		xte::string_view point = ".";
		xte::string_view exp = "EePp";
	};
}

namespace DETAIL_XTE::serialize {
	template<xte::is_arithmetic arithmetic_type>
	struct parse {
		[[nodiscard]] static constexpr arithmetic_type operator()(xte::string_view string, arithmetic_type radix = 10, const xte::serialize_config& config = {}, bool allow_overflow = true) noexcept {
			return DETAIL_XTE::serialize::parse<arithmetic_type>::with_index(string, radix, config, allow_overflow).value;
		}

		[[nodiscard]] static constexpr auto with_index(xte::string_view string, arithmetic_type radix = 10, const xte::serialize_config& config = {}, bool allow_overflow = true) noexcept {
			struct { arithmetic_type value = 0; xte::uz index = 0; } result;
			if (!string.size() || xte::approx_equal(radix, 0) || !xte::is_finite(radix)) {
				return result;
			}
			auto abs_radix = xte::abs(radix);
			bool radix_is_whole = xte::approx_equal(abs_radix, xte::make<xte::uz>(abs_radix));
			xte::string_view digits = config.digits.subview(0, xte::max(2, xte::make<xte::uz>(abs_radix) + !radix_is_whole));
			auto parse_int = [&, radix = (radix_is_whole ? radix : xte::make<arithmetic_type>(abs_radix))] -> arithmetic_type {
				xte::try_unsigned<arithmetic_type> value = 0;
				bool neg = config.minus.contains(string[result.index]);
				for (xte::uz i = result.index + (neg || config.plus.contains(string[result.index])); i < string.size(); result.index = ++i) {
					if (xte::uz digit = digits.find(string[i]); ~digit) {
						if (allow_overflow) {
							value = xte::as_unsigned(xte::add(xte::mul(static_cast<arithmetic_type>(value), radix), xte::make<arithmetic_type>(digit)));
							continue;
						}
						if (auto prod = xte::mul_checked(static_cast<arithmetic_type>(value), radix)) {
							if (auto sum = xte::add_checked(*prod, xte::make<arithmetic_type>(digit + !neg))) {
								value = xte::as_unsigned(*sum) - !neg;
								continue;
							}
						}
					}
					break;
				}
				return static_cast<arithmetic_type>(neg ? -value : value);
			};
			result.value = parse_int();
			if constexpr (xte::is_float<arithmetic_type>) {
				if ((result.index < string.size()) && config.point.contains(string[result.index])) {
					arithmetic_type pow = 1;
					if (!radix_is_whole || (radix > 0)) {
						pow = xte::sign(result.value);
						radix = abs_radix;
					}
					xte::uz digit;
					while ((++result.index < string.size()) && ~(digit = digits.find(string[result.index]))) {
						result.value += xte::make<arithmetic_type>(digit) * (pow /= radix);
					}
				}
				if (((result.index + 1) < string.size()) && config.exp.contains(string[result.index]) && (digits.contains(string[result.index + 1]) || ((result.index + 2 < string.size()) && (config.minus.contains(string[result.index + 1]) || config.plus.contains(string[result.index + 1])) && digits.contains(string[result.index + 2])))) {
					++result.index;
					result.value *= xte::pow(radix, parse_int());
				}
			}
			return result;
		};
	};
}

namespace xte {
	constexpr auto stringify_number = []<xte::is_arithmetic arithmetic_type>[[nodiscard]](arithmetic_type x, arithmetic_type radix = 10, const xte::serialize_config& config = {}, xte::uz max_float_precision = 50) noexcept(false) -> xte::string {
		xte::string result;
		if (xte::is_nan(x)) {
			return "NaN";
		}
		if (xte::is_infinite(x)) {
			return (x < 0) ? "-inf" : "inf";
		}
		if (xte::approx_equal(x, 0) || !xte::is_finite(radix) || xte::approx_equal(radix, 0)) {
			result.append(config.digits[0]);
			if constexpr (xte::is_float<arithmetic_type>) {
				result.append(config.point[0]);
				result.append(config.digits[0]);
			}
			return result;
		}
		bool neg = x < 0;
		auto abs = xte::abs(x);
		auto abs_radix = xte::abs(radix);
		if (xte::approx_equal(abs_radix, 1)) {
			if (radix > 0) {
				result.resize(xte::make<xte::uz>(abs), config.digits[1]);
			} else {
				result.append(config.digits[1]);
				auto length = xte::make<xte::uz>(abs);
				result.reserve_total(length * 2);
				while (--length) {
					result.append(config.digits[0]);
					result.append(config.digits[1]);
				}
			}
			return neg ? (config.minus[0] + xte::as_xvalue(result)) : xte::as_xvalue(result);
		}
		bool radix_is_whole = xte::approx_equal(abs_radix, xte::floor(abs_radix));
		if constexpr (xte::is_int<arithmetic_type>) {
			do {
				if constexpr (xte::is_signed_int<arithmetic_type>) {
					if (radix < 0) {
						do {
							arithmetic_type rem = x % radix;
							x /= radix;
							if (rem < 0) {
								rem -= radix;
								++x;
							}
							result.append(config.digits[static_cast<xte::uz>(rem)]);
						} while (x);
						break;
					}
				}
				do {
					result.append(config.digits[static_cast<xte::uz>(abs % abs_radix)]);
				} while (abs /= abs_radix);
			} while (false);
			std::ranges::reverse(result);
		} else {
			if ((radix < 0) && radix_is_whole) {
				arithmetic_type whole = xte::floor(x);
				arithmetic_type fraction = x - whole;
				xte::array<arithmetic_type> buffer;
				for (xte::uz i = 0; (i < max_float_precision) && (!i || !xte::approx_equal(fraction, 0)); ++i) {
					arithmetic_type digit = xte::floor(fraction *= radix);
					fraction -= digit;
					buffer.append(digit);
				}
				xte::iz carry = 0;
				for (arithmetic_type& digit : buffer | std::views::reverse) {
					digit += xte::make<arithmetic_type>(carry);
					if ((carry = (digit < 0) - xte::approx_greater_equal(digit, abs_radix))) {
						digit += abs_radix * xte::make<arithmetic_type>(carry);
					}
					result.append(config.digits[xte::make<xte::uz>(digit)]);
				}
				result.append(config.point[0]);
				whole += xte::make<arithmetic_type>(carry);
				do {
					arithmetic_type digit = xte::mod(whole, radix);
					whole = xte::floor(whole / radix);
					if (digit < 0) {
						digit -= radix;
						++whole;
					}
					result.append(config.digits[xte::make<xte::uz>(digit)]);
				} while (!xte::approx_equal(whole, 0));
				std::ranges::reverse(result);
			} else if (abs_radix < 1) {
				arithmetic_type power = 1;
				if ((power / abs_radix) > abs) {
					result.append(config.digits[0]);
				} else {
					while (xte::approx_less_equal(power /= abs_radix, abs));
					while ((power *= abs_radix) > 1) {
						auto digit = xte::make<xte::uz>(abs / power);
						abs -= xte::make<arithmetic_type>(digit) * power;
						result.append(config.digits[digit]);
					}
				}
				result.append(config.point[0]);
				do {
					auto digit = xte::make<xte::uz>(abs);
					result.append(config.digits[digit]);
					abs -= xte::make<arithmetic_type>(digit);
					abs /= abs_radix;
				} while (!xte::approx_equal(abs, 0));
				std::ranges::reverse(result);
			} else if (!radix_is_whole) {
				if (abs < 1) {
					result.append(config.digits[0]);
				} else {
					arithmetic_type power = 1;
					while (xte::approx_less_equal(power *= abs_radix, abs));
					while (xte::approx_greater_equal(power /= abs_radix, 1)) {
						auto digit = xte::make<xte::uz>(abs / power);
						abs -= xte::make<arithmetic_type>(digit) * power;
						result.append(config.digits[digit]);
					}
				}
				result.append(config.point[0]);
				for (xte::uz i = 0; (i < max_float_precision) && (!i || !xte::approx_equal(abs, 0)); ++i) {
					auto digit = xte::make<xte::uz>(abs *= abs_radix);
					abs -= xte::make<arithmetic_type>(digit += xte::approx_equal(abs, digit + 1));
					result.append(config.digits[digit]);
				}
			} else {
				arithmetic_type whole = xte::floor(abs);
				abs -= whole;
				do {
					arithmetic_type digit = xte::rem(whole, abs_radix);
					whole = xte::floor(whole / abs_radix);
					result.append(config.digits[xte::make<xte::uz>(digit)]);
				} while (!xte::approx_equal(whole, 0));
				std::ranges::reverse(result);
				result.append(config.point[0]);
				for (xte::uz i = 0; (i < max_float_precision) && (!i || !xte::approx_equal(abs, 0)); ++i) {
					auto digit = xte::make<xte::uz>(abs *= abs_radix);
					abs -= xte::make<arithmetic_type>(digit);
					result.append(config.digits[digit]);
				}
			}
		}
		return (neg && ((radix > 0) || !radix_is_whole)) ? (config.minus[0] + result) : result;
	};


	template<xte::is_arithmetic arithmetic_type>
	constexpr DETAIL_XTE::serialize::parse<arithmetic_type> parse_number;
}

#endif
