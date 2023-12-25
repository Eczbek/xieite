#ifndef XIEITE_HEADER_MATH_PRIME
#	define XIEITE_HEADER_MATH_PRIME

#	include <cmath>
#	include "../concepts/integer.hpp"

namespace xieite::math {
	template<xieite::concepts::Integer Integer>
	constexpr bool prime(const Integer value) noexcept {
		if (value < 4) {
			return value > 1;
		}
		if (!(value % 2) || !(value % 3)) {
			return false;
		}
		const Integer limit = std::sqrt(value);
		for (Integer i = 5; i <= limit; i += 6) {
			if (!(value % i) || !(value % (i + 2))) {
				return false;
			}
		}
		return true;
	}
}

#endif
