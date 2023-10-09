#ifndef XIEITE_HEADER__MATH__SIGN
#	define XIEITE_HEADER__MATH__SIGN

#	include "../concepts/numeric.hpp"
#	include "../math/split_boolean.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr int sign(const Number value) noexcept {
		return xieite::math::splitBoolean(value >= 0);
	}
}

#endif
