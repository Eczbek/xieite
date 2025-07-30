#ifndef DETAIL_XIEITE_HEADER_MATH_WRAP
#	define DETAIL_XIEITE_HEADER_MATH_WRAP
#
#	include <type_traits>
#	include "../math/minmax.hpp"
#	include "../math/mod.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr Arith wrap(Arith x, std::type_identity_t<Arith> limit0, std::type_identity_t<Arith> limit1) noexcept {
		const auto [min, max] = xieite::minmax(limit0, limit1);
		return xieite::mod(x - min, max - min) + min;
	}
}

#endif
