#ifndef DETAIL_XIEITE_HEADER_MATH_DIV_FLOOR
#	define DETAIL_XIEITE_HEADER_MATH_DIV_FLOOR
#
#	include <cmath>
#	include <concepts>
#	include <type_traits>
#	include "../math/sign.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith div_floor(Arith lhs, std::type_identity_t<Arith> rhs) noexcept {
		if constexpr (std::floating_point<Arith>) {
			return std::floor(lhs / rhs);
		} else {
			return static_cast<Arith>(lhs / rhs - !!(lhs % rhs) * (xieite::sign(lhs, rhs) < 0));
		}
	}
}

#endif
