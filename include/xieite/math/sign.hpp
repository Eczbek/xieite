#ifndef XIEITE_HEADER__MATH__SIGN
#	define XIEITE_HEADER__MATH__SIGN

#	include "../concepts/Arithmetic.hpp"
#	include "../math/splitBoolean.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	constexpr int sign(const Arithmetic value) noexcept {
		return xieite::math::splitBoolean(value >= 0);
	}
}

#endif
