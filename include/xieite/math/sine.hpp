#ifndef XIEITE_HEADER_MATH_SINE
#	define XIEITE_HEADER_MATH_SINE

#	include <cmath>
#	include <type_traits>
#	include <utility>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr std::common_type_t<double, Arithmetic_> sine(const Arithmetic_ theta, const bool inverse, const bool hyperbolic, const bool reciprocal) noexcept {
		using Fractional = std::common_type_t<double, Arithmetic_>;
		switch (0b001 * inverse | 0b010 * hyperbolic | 0b100 * reciprocal) {
		case 0b000:
			return std::sin(static_cast<Fractional>(theta));
		case 0b001:
			return std::asin(static_cast<Fractional>(theta));
		case 0b010:
			return std::sinh(static_cast<Fractional>(theta));
		case 0b011:
			return std::asinh(static_cast<Fractional>(theta));
		case 0b100:
			return 1.0 / std::sin(static_cast<Fractional>(theta));
		case 0b101:
			return 1.0 / std::asin(static_cast<Fractional>(theta));
		case 0b110:
			return 1.0 / std::sinh(static_cast<Fractional>(theta));
		case 0b111:
			return 1.0 / std::asinh(static_cast<Fractional>(theta));
		}
		std::unreachable();
	}
}

#endif
