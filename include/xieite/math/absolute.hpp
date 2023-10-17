#ifndef XIEITE_HEADER_MATH_ABSOLUTE
#	define XIEITE_HEADER_MATH_ABSOLUTE

#	include <cmath>
#	include <concepts>
#	include "../math/negative.hpp"
#	include "../types/maybe_unsigned.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr xieite::types::MaybeUnsigned<Integer> absolute(const Integer value) noexcept {
		return static_cast<xieite::types::MaybeUnsigned<Integer>>(xieite::math::negative(value) ? -value : value);
	}

	template<std::floating_point FloatingPoint>
	[[nodiscard]] constexpr FloatingPoint absolute(const FloatingPoint value) noexcept {
		return std::abs(value);
	}
}

#endif
