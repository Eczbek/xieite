#ifndef DETAIL_XIEITE_HEADER_MATH_DIFF
#	define DETAIL_XIEITE_HEADER_MATH_DIFF
#
#	include <cmath>
#	include <type_traits>
#	include "../trait/is_arith.hpp"
#	include "../trait/try_unsigned.hpp"

namespace xieite {
	template<xieite::is_arith Arith>
	[[nodiscard]] constexpr xieite::try_unsigned<Arith> diff(Arith a, std::type_identity_t<Arith> b) noexcept {
		if constexpr (std::floating_point<Arith>) {
			return std::abs(a - b);
		} else {
			using UInt = xieite::try_unsigned<Arith>;
			return (a > b)
				? (static_cast<UInt>(a) - static_cast<UInt>(b))
				: (static_cast<UInt>(b) - static_cast<UInt>(a));
		}
	}
}

#endif
