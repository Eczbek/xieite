#ifndef XIEITE_HEADER_MATH_DIGITS
#	define XIEITE_HEADER_MATH_DIGITS

#	include <concepts>
#	include <cstddef>
#	include "../math/absolute.hpp"
#	include "../math/is_negative.hpp"

namespace xieite::math {
	template<std::integral Integral_>
	[[nodiscard]] constexpr std::size_t digits(Integral_ value, const Integral_ radix = 10) noexcept {
		if (!radix) {
			return 1;
		}
		if (radix == 1) {
			return static_cast<std::size_t>(xieite::math::absolute(value));
		}
		if (std::signed_integral<Integral_> && (radix == static_cast<Integral_>(-1))) {
			return static_cast<std::size_t>(xieite::math::absolute(value) * 2) + 1;
		}
		std::size_t result = 0;
		do {
			value = value / radix + xieite::math::isNegative(value % radix);
			++result;
		} while (value);
		return result;
	}
}

#endif
