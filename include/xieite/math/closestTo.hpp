#ifndef XIEITE_HEADER_MATH_CLOSESTTO
#	define XIEITE_HEADER_MATH_CLOSESTTO

#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/math/Result.hpp>
#	include <xieite/math/difference.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2, xieite::concepts::Arithmetic Number3>
	[[nodiscard]]
	constexpr xieite::math::Result<Number1, Number2, Number3>& closestTo(const Number1 target, Number2& value1, Number3& value2) noexcept {
		return (value1 >= target) ? ((value2 >= target) ? ((value1 < value2) ? value1 : value2) : ((xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value1 : value2)) : ((value2 < target) ? ((value1 > value2) ? value1 : value2) : ((xieite::math::difference(target, value1) < xieite::math::difference(target, value2)) ? value1 : value2));
	}

	template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2, xieite::concepts::Arithmetic Number3>
	[[nodiscard]]
	constexpr const xieite::math::Result<Number1, Number2, Number3>& closestTo(const Number1 target, const Number2& value1, const Number3& value2) noexcept {
		return (value1 >= target) ? ((value2 >= target) ? ((value1 < value2) ? value1 : value2) : ((xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value1 : value2)) : ((value2 < target) ? ((value1 > value2) ? value1 : value2) : ((xieite::math::difference(target, value1) < xieite::math::difference(target, value2)) ? value1 : value2));
	}
}

#endif
