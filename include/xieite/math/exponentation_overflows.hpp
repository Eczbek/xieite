#ifndef XIEITE_HEADER_MATH_EXPONENTATION_OVERFLOWS
#	define XIEITE_HEADER_MATH_EXPONENTATION_OVERFLOWS

#	include <cmath>
#	include <concepts>
#	include <limits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr bool exponentationOverflows(const Arithmetic_ base, const Arithmetic_ exponent) noexcept {
		const auto power = std::pow(base, exponent);
		if constexpr (!std::unsigned_integral<Arithmetic_>) {
			if (power < std::numeric_limits<Arithmetic_>::min()) {
				return true;
			}
		}
		return power > std::numeric_limits<Arithmetic_>::max();
	}
}

#endif
