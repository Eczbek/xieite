#ifndef DETAIL_XIEITE_HEADER_MATH_DIV_CEIL
#	define DETAIL_XIEITE_HEADER_MATH_DIV_CEIL
#
#	include <cmath>
#	include <concepts>
#	include <type_traits>
#	include "../math/sign.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith div_ceil(Arith lhs, std::type_identity_t<Arith> rhs) {
		if constexpr (std::floating_point<Arith>) {
			return std::ceil(lhs / rhs);
		} else {
			return static_cast<Arith>(lhs / rhs + !!(lhs % rhs) * (xieite::sign(lhs, rhs) > 0));
		}
	}
}

#endif
