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

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr std::string stringify(Arithmetic_ value, const std::conditional_t<std::floating_point<Arithmetic_>, xieite::math::SignedSize, Arithmetic_> radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept {
		using Radix = std::conditional_t<std::floating_point<Arithmetic_>, xieite::math::SignedSize, Arithmetic_>;
		if (!static_cast<bool>(value) || !radix) {
			return std::string(1, components.digits[0]);
		}
		const bool negative = xieite::math::isNegative(value);
		std::string result;
		const xieite::types::TryUnsigned<Arithmetic_> absoluteValue = xieite::math::absolute(value);
		if (radix == 1) {
			result = std::string(static_cast<std::size_t>(absoluteValue), components.digits[1]);
		} else if (!std::unsigned_integral<Arithmetic_> && (radix == static_cast<Radix>(-1))) {
			result = components.digits[1];
			std::size_t length = static_cast<std::size_t>(absoluteValue);
			while (--length) {
				result += std::string(1, components.digits[0]) + components.digits[1];
			}
		} else {
			[[maybe_unused]] std::size_t point = 0;
			const auto nextDigit = [&value, radix, components, &result](Radix index) {
				value = static_cast<Arithmetic_>(value / static_cast<Arithmetic_>(radix));
				if (xieite::math::isNegative(index)) {
					index = xieite::math::isNegative(radix) ? (index - radix) : (index + radix);
					++value;
				}
				result.insert(0, 1, components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < components.digits.size())]);
			};
			if constexpr (std::floating_point<Arithmetic_>) {
				value = std::abs(value);
				while (std::abs(std::fmod(value, 1)) > std::numeric_limits<Arithmetic_>::epsilon()) {
					value *= static_cast<Arithmetic_>(radix);
					++point;
				}
			} else {
				if (value == std::numeric_limits<Arithmetic_>::min()) {
					nextDigit(-static_cast<Arithmetic_>(value % radix));
				}
				value = static_cast<Arithmetic_>(xieite::math::absolute(value));
			}
			while ((value >= 1) || (!std::unsigned_integral<Arithmetic_> && (value <= static_cast<Arithmetic_>(-1)))) {
				nextDigit(static_cast<Radix>(xieite::math::remainder(value, static_cast<Arithmetic_>(radix))));
			}
			if constexpr (std::floating_point<Arithmetic_>) {
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

#endif
