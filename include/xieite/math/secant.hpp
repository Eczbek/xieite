#ifndef XIEITE_HEADER__MATH__SECANT
#	define XIEITE_HEADER__MATH__SECANT

#	include <cmath>
#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> secant(const Number value) noexcept {
		return 1 / std::cos(value);
	}
}

#endif
