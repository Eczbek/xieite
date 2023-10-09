#ifndef XIEITE_HEADER__MATH__ABSOLUTE
#	define XIEITE_HEADER__MATH__ABSOLUTE

#	include <cmath>
#	include <concepts>
#	include "../math/attempt_unsign.hpp"
#	include "../types/size_bits.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr xieite::math::AttemptUnsign<Integer> absolute(const Integer value) noexcept {
		const Integer mask = value >> (xieite::types::sizeBits<Integer> - 1);
		return (value ^ mask) - mask;
	}

	template<std::floating_point FloatingPoint>
	[[nodiscard]] constexpr FloatingPoint absolute(const FloatingPoint value) noexcept {
		return std::abs(value);
	}
}

#endif
