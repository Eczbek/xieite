#ifndef XIEITE_HEADER__MATH__LOGARITHM
#	define XIEITE_HEADER__MATH__LOGARITHM

#	include <cmath>
#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	constexpr xieite::math::Result<Number> logarithm(const Number base, const Number value) noexcept {
		return std::log(value) / std::log(base);
	}
}

#endif
