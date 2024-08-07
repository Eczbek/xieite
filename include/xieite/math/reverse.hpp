#ifndef XIEITE_HEADER_MATH_REVERSE
#	define XIEITE_HEADER_MATH_REVERSE

#	include <concepts>
#	include <cstddef>
#	include "../math/is_negative.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<std::integral Integral_>
	[[nodiscard]] constexpr Integral_ reverse(Integral_ value, const Integral_ radix = 10) noexcept {
		const Integral_ sign = static_cast<Integral_>(xieite::math::sign(value));
		value *= sign;
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
		return result * sign;
	}
}

#endif
