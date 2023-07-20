#ifndef XIEITE_HEADER_MATH_COSECANT
#	define XIEITE_HEADER_MATH_COSECANT

#	include <cmath>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/math/Result.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr xieite::math::Result<Number> cosecant(const Number value) noexcept {
		return 1.0 / std::sin(value);
	}
}

#endif
