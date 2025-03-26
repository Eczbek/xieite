#ifndef DETAIL_XIEITE_HEADER_MATH_ALMOST_EQ
#	define DETAIL_XIEITE_HEADER_MATH_ALMOST_EQ
#
#	include <cmath>
#	include <limits>
#	include "../math/abs.hpp"
#	include "../math/diff.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq(T n, T m) noexcept {
		if constexpr (std::floating_point<T>) {
			const T scale = std::abs(n) + std::abs(m);
			// To account for precision loss, take the reciprocal of `scale` if it is less than 1
			return std::abs(n - m) <= (std::numeric_limits<T>::epsilon() * ((scale < 1.0) ? (1.0 / scale) : scale));
		} else {
			return n == m;
		}
	}

	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq(T n, T m, T epsilon) noexcept {
		return xieite::diff(n, m) <= xieite::abs(epsilon);
	}
}

#endif
