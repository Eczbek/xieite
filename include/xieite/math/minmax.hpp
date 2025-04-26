#ifndef DETAIL_XIEITE_HEADER_MATH_MINMAX
#	define DETAIL_XIEITE_HEADER_MATH_MINMAX
#
#	include <algorithm>
#	include <concepts>
#	include "../math/interval.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith, std::convertible_to<Arith>... Ariths>
	[[nodiscard]] constexpr xieite::interval<Arith> minmax(Arith first, Ariths... rest) noexcept {
		auto result = xieite::interval<Arith>(first, first);
		(..., (result = xieite::interval<Arith>(std::min(result.start, rest), std::max(result.end, rest))));
		return result;
	}
}

#endif
