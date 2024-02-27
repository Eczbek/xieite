#ifndef XIEITE_HEADER_MATH_NEGATIVE
#	define XIEITE_HEADER_MATH_NEGATIVE

#	include <concepts>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<std::unsigned_integral UnsignedInteger>
	[[nodiscard]] constexpr bool negative(const UnsignedInteger value) noexcept {
		return false;
	}

	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr bool negative(const Number value) noexcept {
		return value < 0;
	}
}

#endif
