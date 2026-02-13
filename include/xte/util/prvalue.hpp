#ifndef DETAIL_XTE_HEADER_FUNC_PRVALUE
#	define DETAIL_XTE_HEADER_FUNC_PRVALUE
#
#	include "../preproc/lift.hpp"

namespace xte {
	inline constexpr auto prvalue = XTE_LIFT(auto);
}

#endif
