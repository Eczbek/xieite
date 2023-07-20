#ifndef XIEITE_HEADER_MATH_COTANGENT
#	define XIEITE_HEADER_MATH_COTANGENT

#	include <cmath>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/math/Result.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr xieite::math::Result<Number> cotangent(const Number value) noexcept {
		return std::cos(value) / std::sin(value);
	}
}

#endif
