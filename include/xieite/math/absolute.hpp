#ifndef XIEITE_HEADER__MATH__ABSOLUTE
#	define XIEITE_HEADER__MATH__ABSOLUTE

#	include <cmath>
#	include <concepts>
#	include <limits>
#	include "../math/AttemptUnsign.hpp"

namespace xieite::math {
	template<std::integral Integer>
	constexpr xieite::math::AttemptUnsign<Integer> absolute(const Integer value) noexcept {
		return static_cast<xieite::math::AttemptUnsign<Integer>>((value < 0) ? -value : value);
	}

	template<std::floating_point FloatingPoint>
	constexpr FloatingPoint absolute(const FloatingPoint value) noexcept {
		return std::abs(value);
	}
}

#endif
