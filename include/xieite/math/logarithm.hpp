#ifndef XIEITE_HEADER_MATH_LOGARITHM
#	define XIEITE_HEADER_MATH_LOGARITHM

#	include <cmath>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/math/Result.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2>
	[[nodiscard]]
	constexpr xieite::math::Result<Number1, Number2> logarithm(const Number1 base, const Number2 value) noexcept {
		return std::log(value) / std::log(base);
	}
}

#endif
