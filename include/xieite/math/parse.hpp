#ifndef XIEITE_HEADER_MATH_PARSE
#	define XIEITE_HEADER_MATH_PARSE

#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include <string_view>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/split_boolean.hpp"
#	include "../strings/lowercase.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr Number parse(const std::string_view value, const std::conditional_t<std::integral<Number>, Number, std::make_signed_t<std::size_t>> radix = 10, const std::string_view digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", const char negativeSign = '-', const char positiveSign = '+', const char decimalPoint = '.', const char exponentCharacter = 'e') noexcept {
		const bool negative = value[0] == negativeSign;
		const std::size_t valueSize = value.size();
		Number integral = 0;
		Number fractional = 0;
		std::size_t point = 0;
		std::make_signed_t<std::size_t> power = 0;
		for (std::size_t i = negative || (value[0] == positiveSign); i < valueSize; ++i) {
			const std::size_t index = digits.find(value[i]);
			if (index == std::string_view::npos) {
				if constexpr (std::floating_point<Number>) {
					if (value[i] == decimalPoint) {
						if (point) {
							break;
						}
						point = 1;
					} else if (xieite::strings::lowercase(value[i]) == xieite::strings::lowercase(exponentCharacter)) {
						power = xieite::math::parse<std::make_signed_t<std::size_t>>(value.substr(i + 1));
						break;
					}
				} else {
					break;
				}
			} else if constexpr (std::floating_point<Number>) {
				Number& part = (point ? fractional : integral);
				part = part * static_cast<Number>(radix) + static_cast<Number>(index);
				point += !!point;
			} else {
				integral = integral * radix + static_cast<Number>(index);
			}
		}
		if constexpr (std::integral<Number>) {
			return negative ? -integral : integral;
		} else {
			return xieite::math::splitBoolean(!negative) * (integral + fractional / std::pow(radix, point - 1)) * std::pow(radix, power);
		}
	}
}

#endif
