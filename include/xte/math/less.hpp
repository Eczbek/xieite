#ifndef DETAIL_XTE_HEADER_MATH_LESS
#	define DETAIL_XTE_HEADER_MATH_LESS
#
#	include "../math/compare.hpp"
#	include "../preproc/fwd.hpp"
#	include "../preproc/returns.hpp"
#	include <compare>

namespace xte {
	[[nodiscard]] constexpr auto less(auto&& lhs, auto&& rhs) XTE_RETURNS(
		std::is_lt(xte::compare(XTE_FWD(lhs), XTE_FWD(rhs)))
	)
}

#endif
