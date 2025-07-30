#ifndef DETAIL_XIEITE_HEADER_MATH_MINMAX_MAGNITUDE
#	define DETAIL_XIEITE_HEADER_MATH_MINMAX_MAGNITUDE
#
#	include <type_traits>
#	include "../math/closest.hpp"
#	include "../math/farthest.hpp"
#	include "../math/interval.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto minmax_magnitude(xieite::is_arith auto first, xieite::is_arith auto... rest) noexcept {
		using Type = std::common_type_t<decltype(first), decltype(rest)...>;
		auto result = xieite::interval<Type>(first, first);
		(..., (result = xieite::interval<Type>(
			xieite::closest(0, result.start, rest),
			xieite::farthest(0, result.end, rest)
		)));
		return result;
	}
}

#endif
