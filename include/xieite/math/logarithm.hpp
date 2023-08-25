#ifndef XIEITE_HEADER__MATH__LOGARITHM
#	define XIEITE_HEADER__MATH__LOGARITHM

#	include <cmath>
#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2>
	constexpr xieite::math::Result<Number1, Number2> logarithm(const Number1 base, const Number2 value) noexcept {
		return std::log(value) / std::log(base);
	}
}

#endif
