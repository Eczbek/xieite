#ifndef DETAIL_XIEITE_HEADER_MATH_FLOOR_HALF
#	define DETAIL_XIEITE_HEADER_MATH_FLOOR_HALF
#
#	include <type_traits>
#	include "../math/div_floor_half.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith floor_half(Arith x, std::type_identity_t<Arith> step = 1) noexcept {
		return xieite::div_floor_half(x, step) * step;
	}
}

#endif
