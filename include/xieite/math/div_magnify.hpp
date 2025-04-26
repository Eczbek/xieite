#ifndef DETAIL_XIEITE_HEADER_MATH_DIV_MAGNIFY
#	define DETAIL_XIEITE_HEADER_MATH_DIV_MAGNIFY
#
#	include <cmath>
#	include <concepts>
#	include "../math/sign.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template <xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith div_magnify(Arith lhs, Arith rhs) noexcept {
		if constexpr (std::floating_point<Arith>) {
			return std::ceil(lhs / rhs) - ((lhs < 0) != (rhs < 0));
		}
		else {
			return static_cast<Arith>(lhs / rhs + !!(lhs % rhs) * xieite::sign(lhs, rhs));
		}
	}
}

#endif
