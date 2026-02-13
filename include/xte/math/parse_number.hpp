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
#	include "../math/sign.hpp"
#	include "../trait/is_float.hpp"
#	include "../trait/is_number.hpp"
#	include "../util/types.hpp"
#	include <cmath>
#	include <limits>

namespace DETAIL_XTE {
	template<xte::is_number T>
	struct parse_number {
		[[nodiscard]] static constexpr T operator()(xte::string_view string, T radix = 10, const xte::number_format_config& config = {}, bool allow_overflow = true) noexcept {
			return DETAIL_XTE::parse_number<T>::with_index(string, radix, config, allow_overflow).value;
		}

		[[nodiscard]] static constexpr auto with_index(xte::string_view string, T radix = 10, const xte::number_format_config& config = {}, bool allow_overflow = true) noexcept {
			struct { T value = 0; xte::uz index = 0; } result;
			if (!string.size() || xte::approx_equal(radix, 0) || !xte::is_finite(radix)) {
				return result;
			}
			xte::string_view digits = config.digits.substr(0, xte::max(2, static_cast<xte::uz>(xte::abs(radix))));
			auto parse_int = [&] -> T {
				T value = 0;
				bool neg = config.minus.contains(string[result.index]);
				for (xte::uz i = result.index + (neg || config.plus.contains(string[result.index])); i < string.size(); result.index = ++i) {
					if (xte::uz digit = digits.find(string[i]); ~digit) {
						if (allow_overflow) {
							value = xte::add(xte::mul(value, radix), static_cast<T>(digit));
							continue;
						}
						if (auto prod = xte::mul_checked(value, radix)) {
							if (auto sum = xte::add_checked(*prod, static_cast<T>(digit + neg))) {
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
				if (config.point.contains(string[result.index])) {
					auto pow = static_cast<T>(xte::sign(result.value));
					xte::uz digit;
					while ((++result.index < string.size()) && ~(digit = digits.find(string[result.index]))) {
						result.value += static_cast<T>(digit) * (pow /= radix);
					}
				}
				if (result.index += config.exp.contains(string[result.index])) {
					result.value *= std::pow(radix, parse_int());
				}
			}
			return result;
		};
	};
}

namespace xte {
	template<xte::is_number T>
	constexpr DETAIL_XTE::parse_number<T> parse_number;
}

#endif
