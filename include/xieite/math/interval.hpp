#ifndef XIEITE_HEADER_MATH_INTERVAL
#	define XIEITE_HEADER_MATH_INTERVAL

#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	struct Interval {
		Number start;
		Number end;
	};
}

#endif
