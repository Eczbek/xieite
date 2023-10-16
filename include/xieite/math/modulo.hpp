#ifndef XIEITE_HEADER_MATH_MODULO
#	define XIEITE_HEADER_MATH_MODULO

#	include <cmath>
#	include "../concepts/numeric.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr Number modulo(const Number dividend, const Number divisor) noexcept {
		return std::fmod(std::fmod(dividend, divisor) + divisor, divisor);
	}
}

#endif
