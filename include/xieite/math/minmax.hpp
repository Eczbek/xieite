#ifndef DETAIL_XIEITE_HEADER_MATH_MINMAX
#	define DETAIL_XIEITE_HEADER_MATH_MINMAX
#
#	include <algorithm>
#	include <type_traits>
#	include "../math/interval.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto minmax(xieite::is_arith auto first, xieite::is_arith auto... rest) noexcept {
		using Interval = xieite::interval<std::common_type_t<decltype(first), decltype(rest)...>>;
		auto result = Interval(first, first);
		(..., (result = Interval(std::min(result.start, rest), std::max(result.end, rest))));
		return result;
	}
}

#endif
