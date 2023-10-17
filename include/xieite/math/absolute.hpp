#ifndef XIEITE_HEADER_MATH_ABSOLUTE
#	define XIEITE_HEADER_MATH_ABSOLUTE

#	include <cmath>
#	include <concepts>
#	include "../types/maybe_unsigned.hpp"
#	include "../types/size_bits.hpp"

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr xieite::types::MaybeUnsigned<Integer> absolute(const Integer value) noexcept {
		const Integer mask = value >> (xieite::types::sizeBits<Integer> - 1);
		return static_cast<xieite::types::MaybeUnsigned<Integer>>((value ^ mask) - mask);
	}

	template<std::floating_point FloatingPoint>
	[[nodiscard]] constexpr FloatingPoint absolute(const FloatingPoint value) noexcept {
		return std::abs(value);
	}
}

#endif
