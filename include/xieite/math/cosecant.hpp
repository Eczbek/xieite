#ifndef XIEITE_HEADER_MATH_COSECANT
#	define XIEITE_HEADER_MATH_COSECANT

#	include <cmath>
#	include "../concepts/arithmetic.hpp"
#	include "../types/common_floating_point.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr xieite::types::CommonFloatingPoint<Number> cosecant(const Number value) noexcept {
		return 1 / std::sin(static_cast<xieite::types::CommonFloatingPoint<Number>>(value));
	}
}

#endif
