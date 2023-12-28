#ifndef XIEITE_HEADER_MATH_TAU
#	define XIEITE_HEADER_MATH_TAU

#	include "../concepts/arithmetic.hpp"
#	include "../math/pi.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	inline constexpr Number tau = xieite::math::pi<Number> * 2;
}

#endif
