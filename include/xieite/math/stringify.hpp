#ifndef XIEITE_HEADER_MATH_STRINGIFY
#	define XIEITE_HEADER_MATH_STRINGIFY

#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include <string>
#	include <string_view>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/specialization_of.hpp"
#	include "../math/absolute.hpp"
#	include "../math/down.hpp"
#	include "../math/is_negative.hpp"
#	include "../math/signed_size.hpp"
#	include "../strings/number_components.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::math {
	template<std::unsigned_integral>
	struct BigInteger;

	template<typename Number_>
	requires(xieite::concepts::Arithmetic<Number_> || xieite::concepts::SpecializationOf<Number_, xieite::math::BigInteger>)
	[[nodiscard]] constexpr std::string stringify(Number_ value, std::conditional_t<std::floating_point<Number_>, xieite::math::SignedSize, Number_> radix = 10, xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept {
		if (!value || !radix) {
			return std::string(1, components.digits[0]);
		}
		std::string result;
		const bool negative = xieite::math::isNegative(value);
		const xieite::types::TryUnsigned<Number_> absoluteValue = xieite::math::absolute(value);
		if (radix == 1) {
			result = std::string(static_cast<std::size_t>(absoluteValue), components.digits[1]);
		} else if (!std::unsigned_integral<Number_> && (radix == static_cast<std::conditional_t<std::floating_point<Number_>, xieite::math::SignedSize, Number_>>(-1))) {
			result = components.digits[1];
			std::size_t length = static_cast<std::size_t>(absoluteValue);
			while (--length) {
				result += std::string(1, components.digits[0]) + components.digits[1];
			}
		} else {
			const std::size_t digitsSize = components.digits.size();
			if constexpr (std::floating_point<Number_>) {
				if (xieite::math::isNegative(radix)) {
					const Number_ foo = std::abs(static_cast<Number_>(radix));
					const Number_ bar = -foo / (foo + 1);
					const Number_ baz = 1 / (foo + 1);
					Number_ qux = value;
					std::size_t point = 0;
					while ((qux < bar) || (qux >= baz)) {
						++point;
						qux /= -foo;
					}
					do {
						const std::size_t index = static_cast<std::size_t>(-foo * qux - bar);
						qux = qux * -foo - static_cast<Number_>(index);
						if (index == static_cast<std::size_t>(foo)) {
							result += std::string(1, components.digits[index - 1]) + components.digits[0];
						} else {
							result += components.digits[index];
						}
					} while (components.precision-- && (std::abs(qux) >= std::numeric_limits<Number_>::epsilon()));
					result.insert(point, 1, components.points[0]);
				} else {
					Number_ fractional = std::fmod(value, 1);
					Number_ integral = value - fractional;
					do {
						Number_ index = std::fmod(integral, radix);
						integral = xieite::math::down(integral / static_cast<Number_>(radix));
						if (xieite::math::isNegative(index)) {
							index += std::abs(static_cast<Number_>(radix));
							++integral;
						}
						result = components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < digitsSize)] + result;
					} while (std::abs(integral) >= std::numeric_limits<Number_>::epsilon());
					result += components.points[0];
					do {
						fractional *= static_cast<Number_>(radix);
						Number_ index = xieite::math::down(fractional);
						fractional -= index;
						result += components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < digitsSize)];
					} while (components.precision-- && (std::abs(fractional) >= std::numeric_limits<Number_>::epsilon()));
				}
			} else {
				while (value) {
					Number_ index = value % radix;
					value /= radix;
					if (xieite::math::isNegative(index)) {
						index = static_cast<Number_>(static_cast<xieite::types::TryUnsigned<Number_>>(index) + xieite::math::absolute(radix));
						++value;
					}
					result = components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < digitsSize)] + result;
				}
			}
		}
		if (negative && (radix > 0)) {
			result = components.negatives[0] + result;
		}
		return result;
	}
}

#endif
