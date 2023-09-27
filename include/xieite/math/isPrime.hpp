#ifndef XIEITE_HEADER__MATH__IS_PRIME
#	define XIEITE_HEADER__MATH__IS_PRIME

#	include "../concepts/Integer.hpp"

namespace xieite::math {
	template<xieite::concepts::Integer Integer>
	constexpr bool isPrime(const Integer value) noexcept {
		if ((value < 2) || (value > 2) && !(value % 2)) {
			return false;
		}
		for (Integer i = 3; (i * i) <= value; i += 2) {
			if (!(value % i)) {
				return false;
			}
		}
		return true;
	}
}

#endif
