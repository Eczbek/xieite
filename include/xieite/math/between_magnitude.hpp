#ifndef DETAIL_XIEITE_HEADER_MATH_BETWEEN_MAGNITUDE
#	define DETAIL_XIEITE_HEADER_MATH_BETWEEN_MAGNITUDE
#
#	include "../math/minmax_magnitude.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr bool between_magnitude(Arith x, Arith limit0, Arith limit1, bool down_incl = true, bool up_incl = true) noexcept {
		const auto [down, up] = xieite::minmax_magnitude(limit0, limit1);
		return (down_incl ? (x >= down) : (x > down))
			&& (up_incl ? (x <= up) : (x < up));
	}
}

#endif
