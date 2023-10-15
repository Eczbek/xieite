#ifndef XIEITE_HEADER_MATH_IS_PRIME
#	define XIEITE_HEADER_MATH_IS_PRIME

#	include "../concepts/integer.hpp"

namespace xieite::math {
	template<xieite::concepts::Integer Integer>
	[[nodiscard]] constexpr bool isPrime(const Integer value) noexcept {
		if ((value < 2) || (value > 2) && !(value % 2)) {
			return false;
		}
		for (Integer i = 3; value / i >= i; i += 2) {
			if (!(value % i)) {
				return false;
			}
		}
		return true;
	}
}

#endif
