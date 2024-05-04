#ifndef XIEITE_HEADER_MATH_PRODUCT_SIGN
#	define XIEITE_HEADER_MATH_PRODUCT_SIGN

#	include "../concepts/arithmetic.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic... Arithmetics_>
	[[nodiscard]] constexpr int productSign(const Arithmetics_... values) noexcept {
		return (... * xieite::math::sign(values));
	}
}

#endif
