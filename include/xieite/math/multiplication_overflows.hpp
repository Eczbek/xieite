#ifndef XIEITE_HEADER_MATH_MULTIPLICATION_OVERFLOWS
#	define XIEITE_HEADER_MATH_MULTIPLICATION_OVERFLOWS

#	include <concepts>
#	include <limits>
#	include "../math/absolute.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr bool multiplicationOverflows(const Integer value1, const Integer value2) noexcept {
		return value1 && value2 && (xieite::math::absolute(((value1 < 0) == (value2 < 0)) ? std::numeric_limits<Integer>::min() : std::numeric_limits<Integer>::max()) / xieite::math::absolute(value1) < xieite::math::absolute(value2));
	}
}

#endif
