#ifndef XIEITE_HEADER_MATH_IS_PRIME
#	define XIEITE_HEADER_MATH_IS_PRIME

#	include <cmath>
#	include <concepts>

namespace xieite::math {
	template<std::integral Integer>
	[[nodiscard]] constexpr bool isPrime(const Integer value) noexcept {
		if constexpr (!std::same_as<Integer, bool>) {
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
		}
		return true;
	}
}

#endif
