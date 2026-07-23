#ifndef DETAIL_XTE_HEADER_MATH_LESS_EQUAL
#	define DETAIL_XTE_HEADER_MATH_LESS_EQUAL
#
#	include "../math/compare.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include <compare>

namespace xte {
	[[nodiscard]] constexpr auto less_equal(auto&& lhs, auto&& rhs) XTE_RETURNS(
		std::is_lteq(xte::compare(XTE_FWD(lhs), XTE_FWD(rhs)))
	)
}

#endif
