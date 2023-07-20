#ifndef XIEITE_HEADER_MATH_ALMOSTEQUAL
#	define XIEITE_HEADER_MATH_ALMOSTEQUAL

#	include <limits>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/math/Result.hpp>
#	include <xieite/math/absolute.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2>
	[[nodiscard]]
	constexpr bool almostEqual(const Number1 value1, const Number2 value2) noexcept {
		return (xieite::math::absolute(value1 - value2) <= std::numeric_limits<xieite::math::Result<Number1, Number2>>::epsilon());
	}
}

#endif
