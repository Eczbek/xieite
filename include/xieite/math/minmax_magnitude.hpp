#ifndef DETAIL_XIEITE_HEADER_MATH_MINMAX_MAGNITUDE
#	define DETAIL_XIEITE_HEADER_MATH_MINMAX_MAGNITUDE
#
#	include <concepts>
#	include "../math/closest.hpp"
#	include "../math/farthest.hpp"
#	include "../math/interval.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith, std::convertible_to<Arith>... Ariths>
	[[nodiscard]] constexpr xieite::interval<Arith> minmax_magnitude(Arith first, Ariths... rest) noexcept {
		auto result = xieite::interval<Arith>(first, first);
		(..., (result = xieite::interval<Arith>(
			xieite::closest(static_cast<Arith>(0), result.start, static_cast<Arith>(rest)),
			xieite::farthest(static_cast<Arith>(0), result.end, static_cast<Arith>(rest))
		)));
		return result;
	}
}

#endif
