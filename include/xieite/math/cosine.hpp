#ifndef XIEITE_HEADER_MATH_COSINE
#	define XIEITE_HEADER_MATH_COSINE

#	include <cmath>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number_>
	[[nodiscard]] constexpr std::common_type_t<double, Number_> cosine(const Number theta_, const bool inverse_, const bool hyperbolic_, const bool reciprocal_) noexcept {
		using Fractional = std::common_type_t<double, Number_>;
		static constexpr int none = 0b000;
		static constexpr int inverse = 0b001;
		static constexpr int hyperbolic = 0b010;
		static constexpr int reciprocal = 0b100;
		switch (inverse * inverse_ | hyperbolic * hyperbolic_ | reciprocal * reciprocal_) {
		case none:
			return std::cos(static_cast<Fractional>(theta_));
		case inverse:
			return std::acos(static_cast<Fractional>(theta_));
		case hyperbolic:
			return std::cosh(static_cast<Fractional>(theta_));
		case inverse | hyperbolic:
			return std::acosh(static_cast<Fractional>(theta_));
		case reciprocal:
			return 1.0 / std::cos(static_cast<Fractional>(theta_));
		case inverse | reciprocal:
			return 1.0 / std::acos(static_cast<Fractional>(theta_));
		case hyperbolic | reciprocal:
			return 1.0 / std::cosh(static_cast<Fractional>(theta_));
		case inverse | hyperbolic | reciprocal:
			return 1.0 / std::acosh(static_cast<Fractional>(theta_));
		}
	}
}

#endif
