#ifndef XIEITE_HEADER_MATH_DIGITS
#	define XIEITE_HEADER_MATH_DIGITS

#	include <concepts>
#	include <cstddef>
#	include "../math/is_negative.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr std::size_t digits(Integer value, const Integer base = 10) noexcept {
		if (!base) {
			return 0;
		}
		if (base == 1) {
			return value;
		}
		std::size_t result = xieite::math::isNegative(value) != xieite::math::isNegative(radix);
		do {
			value /= base;
			++result;
		} while (value);
		return result;
	}
}

#endif
