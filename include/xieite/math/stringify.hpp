#ifndef XIEITE_HEADER_MATH_STRINGIFY
#	define XIEITE_HEADER_MATH_STRINGIFY

#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include <string>
#	include <string_view>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/string.hpp"
#	include "../concepts/specialization_of_any.hpp"
#	include "../math/absolute.hpp"
#	include "../strings/integer_components.hpp"
#	include "../math/is_negative.hpp"
#	include "../math/round_down.hpp"
#	include "../math/signed_size.hpp"
#	include "../types/maybe_unsigned.hpp"

namespace xieite::math {
	template<std::unsigned_integral>
	struct BigInteger;

	template<std::size_t, bool>
	struct Integer;

	template<xieite::concepts::String String = std::string, typename Number>
	requires(xieite::concepts::Arithmetic<Number> || xieite::concepts::SpecializationOfAny<Number, xieite::math::BigInteger, xieite::math::Integer>)
	[[nodiscard]] constexpr String stringify(Number value, std::conditional_t<std::floating_point<Number>, xieite::math::SignedSize, Number> radix = 10, const xieite::strings::IntegerComponents& components = xieite::strings::IntegerComponents()) noexcept {
		if (!value || !radix) {
			return String(1, components.digits[0]);
		}
		String result;
		const bool negative = xieite::math::isNegative(value);
		xieite::types::MaybeUnsigned<Number> absoluteValue;
		if constexpr (xieite::concepts::Arithmetic<Number>) {
			absoluteValue = xieite::math::absolute(value);
		} else {
			absoluteValue = value.absolute();
		}
		if (radix == 1) {
			result = String(static_cast<std::size_t>(absoluteValue), components.digits[1]);
		} else if (!std::unsigned_integral<Number> && (radix == static_cast<std::conditional_t<std::floating_point<Number>, xieite::math::SignedSize, Number>>(-1))) {
			result = components.digits[1];
			std::size_t length = static_cast<std::size_t>(absoluteValue);
			while (--length) {
				result += String(1, components.digits[0]) + components.digits[1];
			}
		} else {
			const std::size_t digitsSize = components.digits.size();
			if constexpr (std::floating_point<Number>) {
				if (xieite::math::isNegative(radix)) {
					const Number foo = std::abs(static_cast<Number>(radix));
					const Number bar = -foo / (foo + 1);
					const Number baz = 1 / (foo + 1);
					Number qux = value;
					Number point = 0;
					while ((qux < bar) || (qux >= baz)) {
						++point;
						qux /= -foo;
					}
					do {
						const std::size_t index = static_cast<std::size_t>(-foo * qux - bar);
						qux = qux * -foo - static_cast<Number>(index);
						if (index == static_cast<std::size_t>(foo)) {
							result += String(1, components.digits[index - 1]) + components.digits[0];
						} else {
							result += components.digits[index];
						}
					} while (std::abs(qux) >= std::numeric_limits<Number>::epsilon());
					result.insert(point, 1, components.point);
				} else {
					Number fractional = std::fmod(value, 1);
					Number integral = value - fractional;
					do {
						Number index = std::fmod(integral, radix);
						integral = xieite::math::roundDown(integral / static_cast<Number>(radix));
						if (xieite::math::isNegative(index)) {
							index += std::abs(static_cast<Number>(radix));
							++integral;
						}
						result = components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < digitsSize)] + result;
					} while (std::abs(integral) >= std::numeric_limits<Number>::epsilon());
					result += components.point;
					do {
						fractional *= static_cast<Number>(radix);
						Number index = xieite::math::roundDown(fractional);
						fractional -= index;
						result += components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < digitsSize)];
					} while (std::abs(fractional) >= std::numeric_limits<Number>::epsilon());
				}
			} else {
				while (value) {
					Number index = value % radix;
					value /= radix;
					if (xieite::math::isNegative(index)) {
						index = static_cast<Number>(static_cast<xieite::types::MaybeUnsigned<Number>>(index) + xieite::math::absolute(radix));
						++value;
					}
					result = components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < digitsSize)] + result;
				}
			}
		}
		if (negative && (radix > 0)) {
			result = components.negative + result;
		}
		return result;
	}
}

#endif
