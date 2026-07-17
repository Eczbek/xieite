#ifndef DETAIL_XTE_HEADER_MATH_PARSE_NUMBER
#	define DETAIL_XTE_HEADER_MATH_PARSE_NUMBER
#
#	include "../data/string_view.hpp"
#	include "../math/abs.hpp"
#	include "../math/add_checked.hpp"
#	include "../math/approx_equal.hpp"
#	include "../math/is_finite.hpp"
#	include "../math/max.hpp"
#	include "../math/mul_checked.hpp"
#	include "../math/number_format_config.hpp"
#	include "../math/pow.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_float.hpp"
#	include "../util/make.hpp"
#	include "../util/number_types.hpp"

namespace DETAIL_XTE::parse_number {
	template<xte::is_arithmetic T>
	struct impl {
		[[nodiscard]] static constexpr T operator()(xte::string_view string, T radix = 10, const xte::number_format_config& config = {}, bool allow_overflow = true) noexcept {
			return impl::with_index(string, radix, config, allow_overflow).value;
		}

		[[nodiscard]] static constexpr auto with_index(xte::string_view string, T radix = 10, const xte::number_format_config& config = {}, bool allow_overflow = true) noexcept {
			struct { T value = 0; xte::uz index = 0; } result;
			if (!string.size() || xte::approx_equal(radix, 0) || !xte::is_finite(radix)) {
				return result;
			}
			auto abs_radix = xte::abs(radix);
			bool radix_is_whole = xte::approx_equal(abs_radix, xte::make<xte::uz>(abs_radix));
			xte::string_view digits = config.digits.slice(0, xte::max(2, xte::make<xte::uz>(abs_radix) + !radix_is_whole));
			auto parse_int = [&, radix = radix_is_whole ? radix : xte::make<T>(abs_radix)] -> T {
				T value = 0;
				bool neg = config.minus.contains(string[result.index]);
				for (xte::uz i = result.index + (neg || config.plus.contains(string[result.index])); i < string.size(); result.index = ++i) {
					if (xte::uz digit = digits.find(string[i]); ~digit) {
						if (allow_overflow) {
							value = xte::add(xte::mul(value, radix), xte::make<T>(digit));
							continue;
						}
						if (auto prod = xte::mul_checked(value, radix)) {
							if (auto sum = xte::add_checked(*prod, xte::make<T>(digit + neg))) {
								value = *sum - neg;
								continue;
							}
						}
					}
					break;
				}
				return neg ? -value : value;
			};
			result.value = parse_int();
			if constexpr (xte::is_float<T>) {
				if ((result.index < string.size()) && config.point.contains(string[result.index])) {
					T pow = 1;
					if (!radix_is_whole || (radix > 0)) {
						pow = xte::sign(result.value);
						radix = abs_radix;
					}
					xte::uz digit;
					while ((++result.index < string.size()) && ~(digit = digits.find(string[result.index]))) {
						result.value += xte::make<T>(digit) * (pow /= radix);
					}
				}
				if (result.index += config.exp.contains(string[result.index])) {
					result.value *= xte::pow(radix, parse_int());
				}
			}
			return result;
		};
	};
}

namespace xte {
	template<xte::is_arithmetic T>
	constexpr DETAIL_XTE::parse_number::impl<T> parse_number;
}

#endif
