#ifndef DETAIL_XIEITE_HEADER_MATH_DIFF
#	define DETAIL_XIEITE_HEADER_MATH_DIFF
#
#	include <cmath>
#	include "../trait/is_arith.hpp"
#	include "../trait/try_unsigned.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr xieite::try_unsigned<Arith> diff(Arith a, Arith b) noexcept {
		if constexpr (std::floating_point<Arith>) {
			return std::abs(a - b);
		} else {
			using Result = xieite::try_unsigned<Arith>;
			return (a > b)
				? (static_cast<Result>(a) - static_cast<Result>(b))
				: (static_cast<Result>(b) - static_cast<Result>(a));
		}
	}
}

#endif
