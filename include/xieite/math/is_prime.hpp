#ifndef XIEITE_HEADER_MATH_IS_PRIME
#	define XIEITE_HEADER_MATH_IS_PRIME

#	include <cmath>
#	include <concepts>

namespace xieite::math {
	template<std::integral Integral_>
	[[nodiscard]] constexpr bool isPrime(const Integral_ value) noexcept {
		if constexpr (!std::same_as<Integral_, bool>) {
			if (value < 4) {
				return value > 1;
			}
			if (!(value % 2) || !(value % 3)) {
				return false;
			}
			const Integral_ limit = std::sqrt(value);
			for (Integral_ i = 5; i <= limit; i += 6) {
				if (!(value % i) || !(value % (i + 2))) {
					return false;
				}
			}
		}
		return true;
	}
}

#endif
