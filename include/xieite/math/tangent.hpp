#ifndef XIEITE_HEADER_MATH_TANGENT
#	define XIEITE_HEADER_MATH_TANGENT

#	include <cmath>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number_>
	[[nodiscard]] constexpr std::common_type_t<double, Number_> tangent(const Number theta_, const bool inverse_, const bool hyperbolic_, const bool reciprocal_) noexcept {
		using Fractional = std::common_type_t<double, Number_>;
		static constexpr int none = 0b000;
		static constexpr int inverse = 0b001;
		static constexpr int hyperbolic = 0b010;
		static constexpr int reciprocal = 0b100;
		switch (inverse * inverse_ | hyperbolic * hyperbolic_ | reciprocal * reciprocal_) {
		case none:
			return std::tan(static_cast<Fractional>(theta_));
		case inverse:
			return std::atan(static_cast<Fractional>(theta_));
		case hyperbolic:
			return std::tanh(static_cast<Fractional>(theta_));
		case inverse | hyperbolic:
			return std::atanh(static_cast<Fractional>(theta_));
		case reciprocal:
			return 1.0 / std::tan(static_cast<Fractional>(theta_));
		case inverse | reciprocal:
			return 1.0 / std::atan(static_cast<Fractional>(theta_));
		case hyperbolic | reciprocal:
			return 1.0 / std::tanh(static_cast<Fractional>(theta_));
		case inverse | hyperbolic | reciprocal:
			return 1.0 / std::atanh(static_cast<Fractional>(theta_));
		}
	}
}

#endif
