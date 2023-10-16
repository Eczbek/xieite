#ifndef XIEITE_HEADER_MATH_ADDITION_OVERFLOWS
#	define XIEITE_HEADER_MATH_ADDITION_OVERFLOWS

#	include <concepts>
#	include <limits>

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr bool additionOverflows(const Integer value1, const Integer value2) noexcept {
		return value1 && value2 && ((value1 < 0) ? (std::numeric_limits<Integer>::min() - value1 > value2) : (std::numeric_limits<Integer>::max() - value1 < value2));
	}
}

#endif
