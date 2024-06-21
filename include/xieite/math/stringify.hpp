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
#	include "../math/down.hpp"
#	include "../math/is_negative.hpp"
#	include "../math/signed_size.hpp"
#	include "../strings/number_components.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::detail {
	template<typename Value_, typename Radix_>
	[[nodiscard]] constexpr std::string stringifyNumber(Value_ value, Radix_ radix, xieite::strings::NumberComponents components) noexcept {
		if (!value || !radix) {
			return std::string(1, components.digits[0]);
		}
		std::string result;
		const bool negative = xieite::math::isNegative(value);
		const xieite::types::TryUnsigned<Value_> absoluteValue = xieite::math::absolute(value);
		if (radix == 1) {
			result = std::string(static_cast<std::size_t>(absoluteValue), components.digits[1]);
		} else if (!std::unsigned_integral<Value_> && (radix == static_cast<Radix_>(-1))) {
			result = components.digits[1];
			std::size_t length = static_cast<std::size_t>(absoluteValue);
			while (--length) {
				result += std::string(1, components.digits[0]) + components.digits[1];
			}
		} else {
			const std::size_t digitsSize = components.digits.size();
			if constexpr (std::floating_point<Value_>) {
				if (xieite::math::isNegative(radix)) {
					const Value_ foo = std::abs(static_cast<Value_>(radix));
					const Value_ bar = -foo / (foo + 1);
					const Value_ baz = 1 / (foo + 1);
					Value_ qux = value;
					std::size_t point = 0;
					while ((qux < bar) || (qux >= baz)) {
						++point;
						qux /= -foo;
					}
					do {
						const std::size_t index = static_cast<std::size_t>(-foo * qux - bar);
						qux = qux * -foo - static_cast<Value_>(index);
						if (index == static_cast<std::size_t>(foo)) {
							result += std::string(1, components.digits[index - 1]) + components.digits[0];
						} else {
							result += components.digits[index];
						}
					} while (components.precision-- && (std::abs(qux) >= std::numeric_limits<Value_>::epsilon()));
					result.insert(point, 1, components.points[0]);
				} else {
					Value_ fractional = std::fmod(value, 1);
					Value_ integral = value - fractional;
					do {
						Value_ index = std::fmod(integral, radix);
						integral = xieite::math::down(integral / static_cast<Value_>(radix));
						if (xieite::math::isNegative(index)) {
							index += std::abs(static_cast<Value_>(radix));
							++integral;
						}
						result = components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < digitsSize)] + result;
					} while (std::abs(integral) >= std::numeric_limits<Value_>::epsilon());
					result += components.points[0];
					do {
						fractional *= static_cast<Value_>(radix);
						Value_ index = xieite::math::down(fractional);
						fractional -= index;
						result += components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < digitsSize)];
					} while (components.precision-- && (std::abs(fractional) >= std::numeric_limits<Value_>::epsilon()));
				}
			} else {
				while (value) {
					Value_ index = value % radix;
					value /= radix;
					if (xieite::math::isNegative(index)) {
						index = static_cast<Value_>(static_cast<xieite::types::TryUnsigned<Value_>>(index) + xieite::math::absolute(radix));
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

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr std::string stringify(const Arithmetic_ value, const std::conditional_t<std::floating_point<Arithmetic_>, xieite::math::SignedSize, Arithmetic_> radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept {
		return xieite::detail::stringifyNumber(value, radix, components);
	}
}

#endif
