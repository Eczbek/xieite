#ifndef XIEITE_HEADER_MATH_STRINGIFY
#	define XIEITE_HEADER_MATH_STRINGIFY

#	include <cmath>
#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include <string>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/absolute.hpp"
#	include "../math/is_negative.hpp"
#	include "../math/remainder.hpp"
#	include "../math/signed_size.hpp"
#	include "../strings/number_components.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::detail {
	template<typename Value_, typename Radix_>
	requires(std::floating_point<Value_> || std::same_as<Value_, Radix_>)
	[[nodiscard]] constexpr std::string stringifyNumber(Value_ value, Radix_ radix, xieite::strings::NumberComponents components) noexcept {
		if (!static_cast<bool>(value) || !radix) {
			return std::string(1, components.digits[0]);
		}
		const bool negative = xieite::math::isNegative(value);
		std::string result;
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
			[[maybe_unused]] std::size_t point = 0;
			if constexpr (std::floating_point<Value_>) {
				value = std::abs(value);
				while (std::abs(std::fmod(value, 1)) > std::numeric_limits<Value_>::epsilon()) {
					value *= static_cast<Value_>(radix);
					++point;
				}
			} else {
				if (value == std::numeric_limits<Value_>::min()) {
					const Value_ index = -static_cast<Value_>(value % radix);
					value = static_cast<Value_>(value / radix);
					result.insert(0, 1, components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < components.digits.size())]);
				}
				value = static_cast<Value_>(xieite::math::absolute(value));
			}
			while ((value >= 1) || (!std::unsigned_integral<Value_> && (value <= static_cast<Value_>(-1)))) {
				Radix_ index = static_cast<Radix_>(xieite::math::remainder(value, static_cast<Value_>(radix)));
				value = static_cast<Value_>(value / static_cast<Value_>(radix));
				if (xieite::math::isNegative(index)) {
					index = xieite::math::isNegative(radix) ? (index - radix) : (index + radix);
					++value;
				}
				result.insert(0, 1, components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < components.digits.size())]);
			}
			if constexpr (std::floating_point<Value_>) {
				if (point >= result.size()) {
					result.insert(0, point - result.size() + 1, components.digits[0]);
				}
				result.insert(result.size() - point, 1, components.points[0]);
			}
		}
		if (negative) {
			result.insert(0, 1, components.negatives[0]);
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
