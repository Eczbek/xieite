#ifndef XIEITE_HEADER_MATH_ROUND
#	define XIEITE_HEADER_MATH_ROUND

#	include <cmath>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr Arithmetic_ round(const Arithmetic_ value, const Arithmetic_ step = 1) noexcept {
		return std::round(value / step) * step;
	}
}

#endif
