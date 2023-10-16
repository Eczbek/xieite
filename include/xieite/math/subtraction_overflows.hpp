#ifndef XIEITE_HEADER_MATH_SUBTRACTION_OVERFLOWS
#	define XIEITE_HEADER_MATH_SUBTRACTION_OVERFLOWS

#	include <concepts>
#	include <limits>

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr bool subtractionOverflows(const Integer value1, const Integer value2) noexcept {
		return value1 && value2 && ((value2 < 0) ? (std::numeric_limits<Integer>::max() + value2 < value1) : (std::numeric_limits<Integer>::min() + value2 > value1));
	}
}

#endif
