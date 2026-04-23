 #ifndef DETAIL_XTE_HEADER_MATH_STRINGIFY_NUMBER
#	define DETAIL_XTE_HEADER_MATH_STRINGIFY_NUMBER
#
#	include "../data/array.hpp"
#	include "../data/string.hpp"
#	include "../math/approx_equal.hpp"
#	include "../math/floor.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/mod.hpp"
#	include "../math/number_format_config.hpp"
#	include "../math/rem.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_int.hpp"
#	include "../trait/is_number.hpp"
#	include "../trait/is_signed.hpp"
#	include "../util/numbers.hpp"
#	include <algorithm>
#	include <ranges>

namespace xte {
	constexpr auto stringify_number = []<xte::is_number T>[[nodiscard]](T x, T radix = 10, const xte::number_format_config& config = {}, xte::uz max_float_precision = 50) noexcept(false) -> xte::string {
		xte::string result;
		if (!xte::is_finite(x) || xte::approx_equal(x, 0) || !xte::is_finite(radix) || xte::approx_equal(radix, 0)) {
			result.push(config.digits[0]);
			if constexpr (xte::is_float<T>) {
				result.push(config.point[0]);
				result.push(config.digits[0]);
			}
			return result;
		}
		bool neg = x < 0;
		auto abs = xte::abs(x);
		auto abs_radix = xte::abs(radix);
		if (xte::approx_equal(abs_radix, 1)) {
			if (radix > 0) {
				result.resize(static_cast<xte::uz>(abs), config.digits[1]);
			} else {
				result.push(config.digits[1]);
				auto length = static_cast<xte::uz>(abs);
				result.reserve_total(length * 2);
				while (--length) {
					result.push(config.digits[0]);
					result.push(config.digits[1]);
				}
			}
			return neg ? (config.minus[0] + xte::xvalue(result)) : xte::xvalue(result);
		}
		bool radix_is_whole = xte::approx_equal(abs_radix, xte::floor(abs_radix));
		if constexpr (xte::is_int<T>) {
			do {
				if constexpr (xte::is_signed<T>) {
					if (radix < 0) {
						do {
							T rem = x % radix;
							x /= radix;
							if (rem < 0) {
								rem -= radix;
								++x;
							}
							result.push(config.digits[static_cast<xte::uz>(rem)]);
						} while (x);
						break;
					}
				}
				do {
					result.push(config.digits[static_cast<xte::uz>(abs % abs_radix)]);
				} while (abs /= abs_radix);
			} while (false);
			std::ranges::reverse(result);
		} else {
			if ((radix < 0) && radix_is_whole) {
				T whole = xte::floor(x);
				T fraction = x - whole;
				xte::array<T> buffer;
				for (xte::uz i = 0; (i < max_float_precision) && (!i || !xte::approx_equal(fraction, 0)); ++i) {
					T digit = xte::floor(fraction *= radix);
					fraction -= digit;
					buffer.push(digit);
				}
				xte::iz carry = 0;
				for (T& digit : buffer | std::views::reverse) {
					digit += static_cast<T>(carry);
					if ((carry = (digit < 0) - (digit >= abs_radix))) {
						digit += abs_radix * static_cast<T>(carry);
					}
					result.push(config.digits[static_cast<xte::uz>(digit)]);
				}
				result.push(config.point[0]);
				whole += static_cast<T>(carry);
				do {
					T digit = xte::mod(whole, radix);
					whole = xte::floor(whole / radix);
					if (digit < 0) {
						digit -= radix;
						++whole;
					}
					result.push(config.digits[static_cast<xte::uz>(digit)]);
				} while (!xte::approx_equal(whole, 0));
				std::ranges::reverse(result);
			} else if (abs_radix < 1) {
				T power = 1;
				if ((power / abs_radix) > abs) {
					result.push(config.digits[0]);
				} else {
					while ((power /= abs_radix) <= abs);
					while ((power *= abs_radix) > 1) {
						auto digit = static_cast<xte::uz>(abs / power);
						abs -= static_cast<T>(digit) * power;
						result.push(config.digits[digit]);
					}
				}
				result.push(config.point[0]);
				do {
					auto digit = static_cast<xte::uz>(abs);
					result.push(config.digits[digit]);
					abs -= static_cast<T>(digit);
					abs /= abs_radix;
				} while (!xte::approx_equal(abs, 0));
				std::ranges::reverse(result);
			} else if (!radix_is_whole) {
				if (abs < 1) {
					result.push(config.digits[0]);
				} else {
					T power = 1;
					while ((power *= abs_radix) <= abs);
					while ((power /= abs_radix) >= 1) {
						auto digit = static_cast<xte::uz>(abs / power);
						abs -= static_cast<T>(digit) * power;
						result.push(config.digits[digit]);
					}
				}
				result.push(config.point[0]);
				for (xte::uz i = 0; (i < max_float_precision) && (!i || !xte::approx_equal(abs, 0)); ++i) {
					auto digit = static_cast<xte::uz>(abs *= abs_radix);
					abs -= static_cast<T>(digit += xte::approx_equal(abs, digit + 1));
					result.push(config.digits[digit]);
				}
			} else {
				T whole = xte::floor(abs);
				abs -= whole;
				do {
					T digit = xte::rem(whole, abs_radix);
					whole = xte::floor(whole / abs_radix);
					result.push(config.digits[static_cast<xte::uz>(digit)]);
				} while (!xte::approx_equal(whole, 0));
				std::ranges::reverse(result);
				result.push(config.point[0]);
				for (xte::uz i = 0; (i < max_float_precision) && (!i || !xte::approx_equal(abs, 0)); ++i) {
					auto digit = static_cast<xte::uz>(abs *= abs_radix);
					abs -= static_cast<T>(digit);
					result.push(config.digits[digit]);
				}
			}
		}
		return (neg && ((radix > 0) || !radix_is_whole)) ? (config.minus[0] + result) : result;
	};
}

#endif

// TODO: Revise
