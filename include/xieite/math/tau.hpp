#ifndef XIEITE_HEADER_MATH_TAU
#	define XIEITE_HEADER_MATH_TAU

#	include "../concepts/arithmetic.hpp"
#	include "../math/pi.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	inline constexpr Arithmetic_ tau = xieite::math::pi<Arithmetic_> * 2;
}

#endif
