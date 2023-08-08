#ifndef XIEITE_HEADER__MATH__PRODUCT_SIGN
#	define XIEITE_HEADER__MATH__PRODUCT_SIGN

#	include "../concepts/Arithmetic.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic... Arithmetics>
	[[nodiscard]]
	constexpr int productSign(const Arithmetics... values) noexcept {
		return (xieite::math::sign(values) * ...);
	}
}

#endif
