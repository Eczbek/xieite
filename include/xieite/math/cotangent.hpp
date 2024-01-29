#ifndef XIEITE_HEADER_MATH_COTANGENT
#	define XIEITE_HEADER_MATH_COTANGENT

#	include <cmath>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::common_type_t<double, Number> cotangent(const Number value) noexcept {
		return std::cos(static_cast<std::common_type_t<double, Number>>(value)) / std::sin(static_cast<std::common_type_t<double, Number>>(value));
	}
}

#endif
