#ifndef XIEITE_HEADER__MATH__ABSOLUTE
#	define XIEITE_HEADER__MATH__ABSOLUTE

#	include <cmath>
#	include <concepts>
#	include <limits>
#	include "../math/AttemptUnsign.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]]
	constexpr xieite::math::AttemptUnsign<Integer> absolute(const Integer value) noexcept {
		return ((value < 0) ? (std::numeric_limits<xieite::math::AttemptUnsign<Integer>>::max() - value + 1) : value);
	}

	template<std::floating_point Floating>
	[[nodiscard]]
	constexpr Floating absolute(const Floating value) noexcept {
		return std::abs(value);
	}
}

#endif
