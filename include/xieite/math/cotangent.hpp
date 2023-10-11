#ifndef XIEITE_HEADER_MATH_COTANGENT
#	define XIEITE_HEADER_MATH_COTANGENT

#	include <cmath>
#	include "../concepts/numeric.hpp"
#	include "../math/result.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> cotangent(const Number value) noexcept {
		return std::cos(value) / std::sin(value);
	}
}

#endif
