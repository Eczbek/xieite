#ifndef DETAIL_XIEITE_HEADER_MATH_ALMOST_EQ_SLOPE
#	define DETAIL_XIEITE_HEADER_MATH_ALMOST_EQ_SLOPE
#
#	include <cmath>
#	include "../math/almost_eq.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq_slope(T n, T m) noexcept {
		return (std::isinf(n) && std::isinf(m)) || xieite::almost_eq(n, m);
	}

	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq_slope(T n, T m, T epsilon) noexcept {
		return (std::isinf(n) && std::isinf(m)) || xieite::almost_eq(n, m, epsilon);
	}
}

#endif
