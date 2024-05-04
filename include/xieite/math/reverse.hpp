#ifndef XIEITE_HEADER_MATH_REVERSE
#	define XIEITE_HEADER_MATH_REVERSE

#	include <concepts>
#	include <cstddef>
#	include "../math/is_negative.hpp"
#	include "../math/split_boolean.hpp"

namespace xieite::math {
	template<std::integral Integral_>
	[[nodiscard]] constexpr Integral_ reverse(Integral_ value, const Integral_ radix = 10) noexcept {
		const bool negative = xieite::math::isNegative(value);
		value *= xieite::math::splitBoolean(!negative);
		Integral_ result = 0;
		while (value) {
			Integral_ digit = value % radix;
			value /= radix;
			if (xieite::math::isNegative(digit)) {
				digit += xieite::math::absolute(radix);
				++value;
			}
			result = result * radix + digit;
		}
		return result * xieite::math::splitBoolean(!negative);
	}
}

#endif
