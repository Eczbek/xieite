#ifndef XIEITE_HEADER__MATH__DIVIDE_DOWN
#	define XIEITE_HEADER__MATH__DIVIDE_DOWN

#	include <concepts>

namespace xieite::math {
	template<std::integral Integer>
	constexpr Integer divideDown(const Integer dividend, const Integer divisor) noexcept {
		return dividend / divisor;
	}
}

#endif
