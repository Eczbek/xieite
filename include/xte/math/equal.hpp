#ifndef DETAIL_XTE_HEADER_MATH_EQUAL
#	define DETAIL_XTE_HEADER_MATH_EQUAL
#
#	include "../math/compare.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include <compare>

namespace xte {
	[[nodiscard]] constexpr auto equal(auto&& lhs, auto&& rhs) XTE_RETURNS(
		std::is_eq(xte::compare(XTE_FWD(lhs), XTE_FWD(rhs)))
	)
}

#endif
