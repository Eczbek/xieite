#ifndef XIEITE_HEADER_MATH_SINE
#	define XIEITE_HEADER_MATH_SINE

#	include <cmath>
#	include <type_traits>
#	include <utility>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Arithmetic Result = std::common_type_t<double, Arithmetic>>
	[[nodiscard]] constexpr Result sine(const Arithmetic theta, const bool inverse, const bool hyperbolic, const bool reciprocal) noexcept {
		switch ((0b001 * inverse) | (0b010 * hyperbolic) | (0b100 * reciprocal)) {
		case 0b000:
			return std::sin(static_cast<Result>(theta));
		case 0b001:
			return std::asin(static_cast<Result>(theta));
		case 0b010:
			return std::sinh(static_cast<Result>(theta));
		case 0b011:
			return std::asinh(static_cast<Result>(theta));
		case 0b100:
			return 1.0 / std::sin(static_cast<Result>(theta));
		case 0b101:
			return 1.0 / std::asin(static_cast<Result>(theta));
		case 0b110:
			return 1.0 / std::sinh(static_cast<Result>(theta));
		case 0b111:
			return 1.0 / std::asinh(static_cast<Result>(theta));
		}
		std::unreachable();
	}
}

#endif
