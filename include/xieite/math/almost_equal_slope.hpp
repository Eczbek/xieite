#ifndef DETAIL_XIEITE_HEADER_MATH_ALMOST_EQUAL_SLOPE
#	define DETAIL_XIEITE_HEADER_MATH_ALMOST_EQUAL_SLOPE
#
#	include <cmath>
#	include "../math/almost_equal.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr bool almost_equal_slope(Arith a, Arith b) noexcept {
		return (std::isinf(a) && std::isinf(b)) || xieite::almost_equal(a, b);
	}

	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr bool almost_equal_slope(Arith a, Arith b, Arith epsilon) noexcept {
		return (std::isinf(a) && std::isinf(b)) || xieite::almost_equal(a, b, epsilon);
	}
}

#endif
