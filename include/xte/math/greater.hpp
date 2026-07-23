#ifndef DETAIL_XTE_HEADER_MATH_GREATER
#	define DETAIL_XTE_HEADER_MATH_GREATER
#
#	include "../math/compare.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include <compare>

namespace xte {
	[[nodiscard]] constexpr auto greater(auto&& lhs, auto&& rhs) XTE_RETURNS(
		std::is_gt(xte::compare(XTE_FWD(lhs), XTE_FWD(rhs)))
	)
}

#endif
