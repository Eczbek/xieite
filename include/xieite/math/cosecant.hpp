#ifndef XIEITE_HEADER_MATH_COSECANT
#	define XIEITE_HEADER_MATH_COSECANT

#	include <cmath>
#	include "../concepts/arithmetic.hpp"
#	include "../math/result.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> cosecant(const Number value) noexcept {
		return 1 / std::sin(value);
	}
}

#endif
