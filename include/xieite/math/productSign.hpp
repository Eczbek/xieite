#ifndef XIEITE_HEADER__MATH__PRODUCT_SIGN
#	define XIEITE_HEADER__MATH__PRODUCT_SIGN

#	include "../concepts/Numeric.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	constexpr int productSign(const Numbers... values) noexcept {
		return (... * xieite::math::sign(values));
	}
}

#endif
