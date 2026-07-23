#ifndef DETAIL_XTE_HEADER_MATH_GREATER_EQUAL
#	define DETAIL_XTE_HEADER_MATH_GREATER_EQUAL
#
#	include "../math/compare.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include <compare>

namespace xte {
	[[nodiscard]] constexpr auto greater_equal(auto&& lhs, auto&& rhs) XTE_RETURNS(
		std::is_gteq(xte::compare(XTE_FWD(lhs), XTE_FWD(rhs)))
	)
}

#endif
