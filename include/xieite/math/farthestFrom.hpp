#ifndef XIEITE_HEADER__MATH__FARTHEST_FROM
#	define XIEITE_HEADER__MATH__FARTHEST_FROM

#	include "../concepts/Numeric.hpp"
#	include "../math/difference.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	constexpr Number& farthestFrom(const Number target, Number& value1, Number& value2) noexcept {
		return (value1 >= target) ? ((value2 >= target) ? ((value1 > value2) ? value1 : value2) : ((xieite::math::difference(target, value1) < xieite::math::difference(target, value2)) ? value1 : value2)) : ((value2 < target) ? ((value1 < value2) ? value1 : value2) : ((xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value1 : value2));
	}

	template<xieite::concepts::Numeric Number>
	constexpr const Number& farthestFrom(const Number target, const Number& value1, const Number& value2) noexcept {
		return (value1 >= target) ? ((value2 >= target) ? ((value1 > value2) ? value1 : value2) : ((xieite::math::difference(target, value1) < xieite::math::difference(target, value2)) ? value1 : value2)) : ((value2 < target) ? ((value1 < value2) ? value1 : value2) : ((xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value1 : value2));
	}
}

#endif
