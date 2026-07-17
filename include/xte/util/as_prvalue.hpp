#ifndef DETAIL_XTE_HEADER_FUNC_AS_PRVALUE
#	define DETAIL_XTE_HEADER_FUNC_AS_PRVALUE
#
#	include "../preproc/lift.hpp"

namespace xte {
	inline constexpr auto as_prvalue = XTE_LIFT_UNARY(auto);
}

#endif
