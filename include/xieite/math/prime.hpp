#ifndef DETAIL_XIEITE_HEADER_MATH_PRIME
#	define DETAIL_XIEITE_HEADER_MATH_PRIME
#
#	include <cmath>
#	include <concepts>

namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr bool prime(T n) noexcept {
		if constexpr (!std::same_as<T, bool>) {
			if (n < 4) {
				return n > 1;
			}
			if (!(n % 2) || !(n % 3)) {
				return false;
			}
			const T sqrt = static_cast<T>(std::sqrt(n));
			for (T i = 5; i <= sqrt; i += 6) {
				if (!(n % i) || !(n % (i + 2))) {
					return false;
				}
			}
		}
		return true;
	}
}

#endif
