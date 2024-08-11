#ifndef XIEITE_HEADER_MATH_IS_NEGATIVE
#	define XIEITE_HEADER_MATH_IS_NEGATIVE

#	include <concepts>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr bool isNegative(const Arithmetic_ value) noexcept {
		if constexpr (!std::unsigned_integral<Arithmetic_>) {
			return value < 0;
		} else {
			return false;
		}
	}
}

#endif
