#ifndef XIEITE_HEADER_MATH_EXPONENTATION_OVERFLOWS
#	define XIEITE_HEADER_MATH_EXPONENTATION_OVERFLOWS

#	include <cmath>
#	include <concepts>
#	include <limits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr bool exponentationOverflows(const Number base, const Number exponent) noexcept {
		const auto power = std::pow(base, exponent);
		if constexpr (!std::unsigned_integral<Number>) {
			if (power < std::numeric_limits<Number>::min()) {
				return true;
			}
		}
		return power > std::numeric_limits<Number>::max();
	}
}

#endif
