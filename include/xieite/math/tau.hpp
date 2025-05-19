#ifndef DETAIL_XIEITE_HEADER_MATH_TAU
#	define DETAIL_XIEITE_HEADER_MATH_TAU
#
#	include "../math/pi.hpp"
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith = double>
	constexpr Arith tau = xieite::pi<Arith> * 2;
}

#endif
