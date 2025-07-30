#ifndef DETAIL_XIEITE_HEADER_MATH_FLOOR
#	define DETAIL_XIEITE_HEADER_MATH_FLOOR
#
#	include <type_traits>
#	include "../math/div_floor.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith floor(Arith x, std::type_identity_t<Arith> step = 1) noexcept {
		return xieite::div_floor(x, step) * step;
	}
}

#endif
