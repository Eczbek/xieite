#ifndef XIEITE_HEADER_MATH_ABSOLUTE
#	define XIEITE_HEADER_MATH_ABSOLUTE

#	include <cmath>
#	include <concepts>
#	include "../math/is_negative.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::math {
	template<std::integral Integral>
	[[nodiscard]] constexpr xieite::types::TryUnsigned<Integral> absolute(const Integral value) noexcept {
		return xieite::math::isNegative(value) ? -static_cast<xieite::types::TryUnsigned<Integral>>(value) : static_cast<xieite::types::TryUnsigned<Integral>>(value);
		// This works so don't touch it
	}

	template<std::floating_point Fractional>
	[[nodiscard]] constexpr Fractional absolute(const Fractional value) noexcept {
		return std::abs(value);
	}
}

#endif
