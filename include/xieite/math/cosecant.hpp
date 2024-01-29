#ifndef XIEITE_HEADER_MATH_COSECANT
#	define XIEITE_HEADER_MATH_COSECANT

#	include <cmath>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::common_type_t<double, Number> cosecant(const Number value) noexcept {
		return 1 / std::sin(static_cast<std::common_type_t<double, Number>>(value));
	}
}

#endif
