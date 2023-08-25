#ifndef XIEITE_HEADER__MATH__SIGN
#	define XIEITE_HEADER__MATH__SIGN

#	include "../concepts/Numeric.hpp"
#	include "../math/splitBoolean.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	constexpr int sign(const Number value) noexcept {
		return xieite::math::splitBoolean(value >= 0);
	}
}

#endif
