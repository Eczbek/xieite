#ifndef DETAIL_XIEITE_HEADER_MATH_SIN
#	define DETAIL_XIEITE_HEADER_MATH_SIN
#
#	include <cmath>
#	include <type_traits>
#	include <utility>
#	include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith Arith, xieite::is_arith Result = std::common_type_t<Arith, double>>
	[[nodiscard]] constexpr Result sin(Arith theta, bool inverse = false, bool hyperbolic = false, bool reciprocal = false) noexcept {
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
