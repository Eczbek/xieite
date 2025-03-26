#ifndef DETAIL_XIEITE_HEADER_MATH_WRAP
#	define DETAIL_XIEITE_HEADER_MATH_WRAP
#
#	include "../math/minmax.hpp"
#	include "../math/mod.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T wrap(T n, T limit0, T limit1) noexcept {
		const auto [min, max] = xieite::minmax(limit0, limit1);
		return xieite::mod(n - min, max - min) + min;
	}
}

#endif
