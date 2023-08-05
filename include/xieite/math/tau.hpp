#ifndef XIEITE_HEADER__MATH__TAU
#	define XIEITE_HEADER__MATH__TAU

#	include "../concepts/Arithmetic.hpp"
#	include "../math/pi.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	inline constexpr Arithmetic tau = xieite::math::pi<Arithmetic> * 2;
}

// τ

#endif
