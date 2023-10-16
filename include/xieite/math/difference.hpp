#ifndef XIEITE_HEADER_MATH_DIFFERENCE
#	define XIEITE_HEADER_MATH_DIFFERENCE

#	include <type_traits>
#	include "../concepts/numeric.hpp"
#	include "../math/attempt_unsign.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::AttemptUnsign<Number> difference(const Number value1, const Number value2) noexcept {
		return (value1 > value2) ? (static_cast<xieite::math::AttemptUnsign<Number>>(value1) - static_cast<xieite::math::AttemptUnsign<Number>>(value2)) : (static_cast<xieite::math::AttemptUnsign<Number>>(value2) - static_cast<xieite::math::AttemptUnsign<Number>>(value1));
	}
}

#endif
