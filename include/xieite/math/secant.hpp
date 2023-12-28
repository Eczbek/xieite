#ifndef XIEITE_HEADER_MATH_SECANT
#	define XIEITE_HEADER_MATH_SECANT

#	include <cmath>
#	include "../concepts/arithmetic.hpp"
#	include "../math/result.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> secant(const Number value) noexcept {
		return 1 / std::cos(value);
	}
}

#endif
