#ifndef XIEITE_HEADER_MATH_COSINE
#	define XIEITE_HEADER_MATH_COSINE

#	include <cmath>
#	include <type_traits>
#	include <utility>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic, xieite::concepts::Arithmetic Result = std::common_type_t<double, Arithmetic>>
	[[nodiscard]] constexpr Result cosine(const Arithmetic theta, const bool inverse, const bool hyperbolic, const bool reciprocal) noexcept {
		switch ((0b001 * inverse) | (0b010 * hyperbolic) | (0b100 * reciprocal)) {
		case 0b000:
			return std::cos(static_cast<Result>(theta));
		case 0b001:
			return std::acos(static_cast<Result>(theta));
		case 0b010:
			return std::cosh(static_cast<Result>(theta));
		case 0b011:
			return std::acosh(static_cast<Result>(theta));
		case 0b100:
			return 1.0 / std::cos(static_cast<Result>(theta));
		case 0b101:
			return 1.0 / std::acos(static_cast<Result>(theta));
		case 0b110:
			return 1.0 / std::cosh(static_cast<Result>(theta));
		case 0b111:
			return 1.0 / std::acosh(static_cast<Result>(theta));
		}
		std::unreachable();
	}
}

#endif
