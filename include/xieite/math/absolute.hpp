#ifndef XIEITE_HEADER_MATH_ABSOLUTE
#	define XIEITE_HEADER_MATH_ABSOLUTE

#	include <cmath>
#	include <concepts>
#	include "../math/is_negative.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::math {
	template<std::integral Integral_>
	[[nodiscard]] constexpr xieite::types::TryUnsigned<Integral_> absolute(const Integral_ value) noexcept {
		return xieite::math::isNegative(value) ? -static_cast<xieite::types::TryUnsigned<Integral_>>(value) : static_cast<xieite::types::TryUnsigned<Integral_>>(value);
		// This works so don't touch it
	}

	template<std::floating_point Fractional_>
	[[nodiscard]] constexpr Fractional_ absolute(const Fractional_ value) noexcept {
		return std::abs(value);
	}
}

#endif
