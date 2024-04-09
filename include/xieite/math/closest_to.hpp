#ifndef XIEITE_HEADER_MATH_CLOSEST_TO
#	define XIEITE_HEADER_MATH_CLOSEST_TO

#	include <concepts>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/difference.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr Number& closestTo(const Number target, Number& value1, Number& value2) noexcept {
		return (xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value2 : value1;
	}

	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr Number closestTo(const Number target, const Number& value1, const Number& value2) noexcept {
		Number copy1 = value1;
		Number copy2 = value2;
		return xieite::math::closestTo(target, copy1, copy2);
	}
}

#endif
