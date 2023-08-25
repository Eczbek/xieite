#ifndef XIEITE_HEADER__MATH__CLOSEST_TO
#	define XIEITE_HEADER__MATH__CLOSEST_TO

#	include "../concepts/Numeric.hpp"
#	include "../math/Result.hpp"
#	include "../math/difference.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2, xieite::concepts::Numeric Number3>
	constexpr xieite::math::Result<Number1, Number2, Number3>& closestTo(const Number1 target, Number2& value1, Number3& value2) noexcept {
		return (value1 >= target) ? ((value2 >= target) ? ((value1 < value2) ? value1 : value2) : ((xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value1 : value2)) : ((value2 < target) ? ((value1 > value2) ? value1 : value2) : ((xieite::math::difference(target, value1) < xieite::math::difference(target, value2)) ? value1 : value2));
	}

	template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2, xieite::concepts::Numeric Number3>
	constexpr const xieite::math::Result<Number1, Number2, Number3>& closestTo(const Number1 target, const Number2& value1, const Number3& value2) noexcept {
		return (value1 >= target) ? ((value2 >= target) ? ((value1 < value2) ? value1 : value2) : ((xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value1 : value2)) : ((value2 < target) ? ((value1 > value2) ? value1 : value2) : ((xieite::math::difference(target, value1) < xieite::math::difference(target, value2)) ? value1 : value2));
	}
}

#endif
