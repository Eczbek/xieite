#ifndef DETAIL_XIEITE_HEADER_MATH_BETWEEN
#	define DETAIL_XIEITE_HEADER_MATH_BETWEEN
#
#	include <type_traits>
#	include "../math/minmax.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr bool between(Arith x, std::type_identity_t<Arith> limit0, std::type_identity_t<Arith> limit1, bool lower_incl = true, bool upper_incl = true) noexcept {
		const auto [lower, upper] = xieite::minmax(limit0, limit1);
		return (lower_incl ? (x >= lower) : (x > lower))
			&& (upper_incl ? (x <= upper) : (x < upper));
	}
}

#endif
