#ifndef XIEITE_HEADER__MATH__DIFFERENCE
#	define XIEITE_HEADER__MATH__DIFFERENCE

#	include <cmath>
#	include <concepts>
#	include <type_traits>

namespace xieite::math {
	template<std::integral Integer>
	constexpr std::make_unsigned_t<Integer> difference(const Integer a, const Integer b) noexcept {
		return (a > b) ? (static_cast<std::make_unsigned_t<Integer>>(a) - static_cast<std::make_unsigned_t<Integer>>(b)) : (static_cast<std::make_unsigned_t<Integer>>(b) - static_cast<std::make_unsigned_t<Integer>>(a));
	}

	template<std::floating_point Floating>
	constexpr Floating difference(const Floating a, const Floating b) noexcept {
		return std::abs(a - b);
	}
}

#endif
