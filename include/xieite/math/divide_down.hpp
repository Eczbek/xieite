#ifndef XIEITE_HEADER_MATH_DIVIDE_DOWN
#	define XIEITE_HEADER_MATH_DIVIDE_DOWN

#	include <concepts>

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr Integer divideDown(const Integer dividend, const Integer divisor) noexcept {
		return dividend / divisor;
	}
}

#endif
