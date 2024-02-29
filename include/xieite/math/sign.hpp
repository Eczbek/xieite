#ifndef XIEITE_HEADER_MATH_SIGN
#	define XIEITE_HEADER_MATH_SIGN

#	include "../concepts/arithmetic.hpp"
#	include "../math/is_negative.hpp"
#	include "../math/split_boolean.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr int sign(const Number value) noexcept {
		return xieite::math::splitBoolean(!xieite::math::isNegative(value));
	}
}

#endif
