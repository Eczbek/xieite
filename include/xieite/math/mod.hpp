#ifndef DETAIL_XIEITE_HEADER_MATH_MOD
#	define DETAIL_XIEITE_HEADER_MATH_MOD
#
#	include "../math/rem.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith mod(Arith lhs, Arith rhs) noexcept {
		return xieite::rem(xieite::rem(lhs, rhs) + rhs * (xieite::sign(lhs) != xieite::sign(rhs)), rhs);
	}
}

#endif
