#ifndef XIEITE_HEADER__MATH__TAU
#	define XIEITE_HEADER__MATH__TAU

#	include "../concepts/Numeric.hpp"
#	include "../math/pi.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	inline constexpr Number tau = xieite::math::pi<Number> * 2;
}

// τ

#endif
