#ifndef DETAIL_XIEITE_HEADER_MATH_PI
#	define DETAIL_XIEITE_HEADER_MATH_PI
#
#	include <concepts>
#	include <numbers>
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith = double>
	constexpr Arith pi = std::numbers::pi_v<Arith>;

	template<std::integral Int>
	constexpr Int pi<Int> = static_cast<Int>(std::numbers::pi);
}

#endif
