#ifndef DETAIL_XIEITE_HEADER_MATH_BETW
#	define DETAIL_XIEITE_HEADER_MATH_BETW
#
#	include "../math/minmax.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool betw(T n, T limit0, T limit1, bool lower_incl = true, bool upper_incl = true) noexcept {
		const auto [lower, upper] = xieite::minmax(limit0, limit1);
		return (lower_incl ? (n >= lower) : (n > lower))
			&& (upper_incl ? (n <= upper) : (n < upper));
	}
}

#endif
