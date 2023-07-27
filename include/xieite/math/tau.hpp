#ifndef XIEITE_HEADER_MATH_TAU
#	define XIEITE_HEADER_MATH_TAU

#	include "../concepts/Arithmetic.hpp"
#	include "../math/pi.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	inline constexpr Arithmetic tau = xieite::math::pi<Arithmetic> * 2.0;
}

// τ

#endif
