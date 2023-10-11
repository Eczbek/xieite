#ifndef XIEITE_HEADER_MATH_PRODUCT_SIGN
#	define XIEITE_HEADER_MATH_PRODUCT_SIGN

#	include "../concepts/numeric.hpp"
#	include "../math/sign.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric... Numbers>
	[[nodiscard]] constexpr int productSign(const Numbers... values) noexcept {
		return (... * xieite::math::sign(values));
	}
}

#endif
