#ifndef XIEITE_HEADER_MATH_STRINGIFY
#	define XIEITE_HEADER_MATH_STRINGIFY

#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include <string>
#	include <string_view>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/absolute.hpp"
#	include "../math/negative.hpp"
#	include "../math/round_down.hpp"
#	include "../types/maybe_unsigned.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::string stringify(Number value, std::conditional_t<std::integral<Number>, Number, std::make_signed_t<std::size_t>> radix = 10, const std::string_view digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", const char negativeSign = '-', const char decimalPoint = '.') noexcept {
		if (!value || !radix) {
			return "";
		}
		if (!value) {
			return "0";
		}
		std::string result;
		const bool negative = xieite::math::negative(value);
		const xieite::types::MaybeUnsigned<Number> absoluteValue = xieite::math::absolute(value);
		if (radix == 1) {
			result = std::string(static_cast<std::size_t>(absoluteValue), digits[1]);
		} else if (!std::unsigned_integral<Number> && (radix == static_cast<std::conditional_t<std::integral<Number>, Number, std::make_signed_t<std::size_t>>>(-1))) {
			result = digits[1];
			std::size_t length = static_cast<std::size_t>(absoluteValue);
			while (--length) {
				result += std::string(1, digits[0]) + digits[1];
			}
		} else {
			const std::size_t digitsSize = digits.size();
			if constexpr (std::integral<Number>) {
				while (value) {
					Number index = value % radix;
					value /= radix;
					if (xieite::math::negative(index)) {
						if (xieite::math::negative(radix)) {
							index -= radix;
						} else {
							index += radix;
						}
						++value;
					}
					result = digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < digitsSize)] + result;
				}
			} else {
				if (radix < 0) {
					const Number foo = std::abs(static_cast<Number>(radix));
					const Number bar = -foo / (foo + 1);
					const Number baz = 1 / (foo + 1);
					Number qux = value;
					Number position = 0;
					while ((qux <= bar) || (qux >= baz)) {
						++position;
						qux = value / std::pow(-foo, position);
					}
					do {
						const std::size_t index = static_cast<std::size_t>(-foo * qux - bar);
						qux = -foo * qux - static_cast<Number>(index);
						if (!position) {
							result += decimalPoint;
						}
						if (index == static_cast<std::size_t>(foo)) {
							result += std::string(1, digits[index - 1]) + digits[0];
						} else {
							result += digits[index];
						}
						--position;
					} while (qux);
				} else {
					Number fractional = std::fmod(value, 1);
					Number integral = value - fractional;
					do {
						Number index = std::fmod(integral, radix);
						integral = xieite::math::roundDown(integral / static_cast<Number>(radix));
						if (index < 0) {
							index += std::abs(static_cast<Number>(radix));
							++integral;
						}
						result = digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < digitsSize)] + result;
					} while (std::abs(integral) >= std::numeric_limits<Number>::epsilon());
					result += decimalPoint;
					do {
						fractional *= static_cast<Number>(radix);
						Number index = xieite::math::roundDown(fractional);
						fractional -= index;
						result += digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < digitsSize)];
					} while (std::abs(fractional) >= std::numeric_limits<Number>::epsilon());
				}
			}
		}
		if (negative && (radix > 0)) {
			result = negativeSign + result;
		}
		return result;
	}
}

#endif
