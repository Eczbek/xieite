#ifndef DETAIL_XIEITE_HEADER_MATH_PRIME
#	define DETAIL_XIEITE_HEADER_MATH_PRIME
#
#	include <cmath>
#	include <concepts>

namespace xieite {
	template<std::integral Int>
	[[nodiscard]] constexpr bool prime(Int x) noexcept {
		if constexpr (!std::same_as<Int, bool>) {
			if (x < 4) {
				return x > 1;
			}
			if (!(x % 2) || !(x % 3)) {
				return false;
			}
			const Int sqrt = static_cast<Int>(std::sqrt(x));
			for (Int i = 5; i <= sqrt; i += 6) {
				if (!(x % i) || !(x % (i + 2))) {
					return false;
				}
			}
		}
		return true;
	}
}

#endif
