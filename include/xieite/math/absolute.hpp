#ifndef XIEITE_HEADER_MATH_ABSOLUTE
#	define XIEITE_HEADER_MATH_ABSOLUTE

#	include <cmath>
#	include <concepts>
#	include "../math/is_negative.hpp"
#	include "../types/maybe_unsigned.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr xieite::types::MaybeUnsigned<Integer> absolute(const Integer value) noexcept {
		return xieite::math::isNegative(value) ? -static_cast<xieite::types::MaybeUnsigned<Integer>>(value) : static_cast<xieite::types::MaybeUnsigned<Integer>>(value); // This works so don't touch it
	}

	template<std::floating_point FloatingPoint>
	[[nodiscard]] constexpr FloatingPoint absolute(const FloatingPoint value) noexcept {
		return std::abs(value);
	}
}

#endif
