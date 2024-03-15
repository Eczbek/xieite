#ifndef XIEITE_HEADER_MATH_REVERSE
#	define XIEITE_HEADER_MATH_REVERSE

#	include <concepts>
#	include <cstddef>
#	include "../math/is_negative.hpp"
#	include "../math/split_boolean.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer reverse(Integer value, const Integer radix = 10) noexcept {
		const bool negative = xieite::math::isNegative(value);
		value *= xieite::math::splitBoolean(!negative);
		Integer result = 0;
		while (value) {
			Integer digit = value % radix;
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
