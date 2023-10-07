#ifndef XIEITE_HEADER__MATH__COTANGENT
#	define XIEITE_HEADER__MATH__COTANGENT

#	include <cmath>
#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> cotangent(const Number value) noexcept {
		return std::cos(value) / std::sin(value);
	}
}

#endif
