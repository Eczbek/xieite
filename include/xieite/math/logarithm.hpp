#ifndef XIEITE_HEADER_MATH_LOGARITHM
#	define XIEITE_HEADER_MATH_LOGARITHM

#	include <cmath>
#	include "../concepts/arithmetic.hpp"
#	include "../types/common_floating_point.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2>
	[[nodiscard]] constexpr xieite::types::CommonFloatingPoint<Number1, Number2> logarithm(const Number1 base, const Number2 value) noexcept {
		return std::log(static_cast<xieite::types::CommonFloatingPoint<Number1, Number2>>(value)) / std::log(static_cast<xieite::types::CommonFloatingPoint<Number1, Number2>>(base));
		// I found std::log to be slightly faster than std::log2 and std::log10
	}
}

#endif
