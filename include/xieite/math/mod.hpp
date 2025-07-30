#ifndef DETAIL_XIEITE_HEADER_MATH_MOD
#	define DETAIL_XIEITE_HEADER_MATH_MOD
#
#	include <type_traits>
#	include "../math/rem.hpp"
#	include "../math/sign.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith mod(Arith lhs, std::type_identity_t<Arith> rhs) noexcept {
		return xieite::rem(xieite::rem(lhs, rhs) + rhs * (xieite::sign(lhs) != xieite::sign(rhs)), rhs);
	}
}

#endif
