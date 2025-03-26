#ifndef DETAIL_XIEITE_HEADER_MATH_INTERVAL
#	define DETAIL_XIEITE_HEADER_MATH_INTERVAL
#
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	struct interval {
		T start;
		T end;
	};
}

#endif
