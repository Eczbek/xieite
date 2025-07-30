#ifndef DETAIL_XIEITE_HEADER_MATH_CLOSEST
#	define DETAIL_XIEITE_HEADER_MATH_CLOSEST
#
#	include <type_traits>
#	include "../math/diff.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	[[nodiscard]] constexpr auto closest(xieite::is_arith auto target, xieite::is_arith auto first, xieite::is_arith auto... rest) noexcept {
		std::common_type_t<decltype(first), decltype(rest)...> result = first;
		(..., ((xieite::diff(target, rest) < xieite::diff(target, first)) && (result = rest)));
		return result;
	}
}

#endif
