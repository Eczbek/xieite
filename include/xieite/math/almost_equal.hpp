#ifndef DETAIL_XIEITE_HEADER_MATH_ALMOST_EQUAL
#	define DETAIL_XIEITE_HEADER_MATH_ALMOST_EQUAL
#
#	include <cmath>
#	include <limits>
#	include "../math/abs.hpp"
#	include "../math/diff.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr bool almost_equal(Arith a, Arith b) noexcept {
		if constexpr (std::floating_point<Arith>) {
			const Arith scale = std::abs(a) + std::abs(b);
			// To account for precision loss, take the reciprocal of `scale` if it is less than 1
			return std::abs(a - b) <= (std::numeric_limits<Arith>::epsilon() * ((scale < 1.0) ? (1.0 / scale) : scale));
		} else {
			return a == b;
		}
	}

	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr bool almost_equal(Arith a, Arith b, Arith epsilon) noexcept {
		return xieite::diff(a, b) <= xieite::abs(epsilon);
	}
}

#endif
