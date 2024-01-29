#ifndef XIEITE_HEADER_MATH_SECANT
#	define XIEITE_HEADER_MATH_SECANT

#	include <cmath>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::common_type_t<double, Number> secant(const Number value) noexcept {
		return 1 / std::cos(static_cast<std::common_type_t<double, Number>>(value));
	}
}

#endif
