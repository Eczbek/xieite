#ifndef XIEITE_HEADER_MATH_MODULO
#	define XIEITE_HEADER_MATH_MODULO

#	include <cmath>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic modulo(const Arithmetic dividend, const Arithmetic divisor) noexcept {
		return std::fmod(std::fmod(dividend, divisor) + divisor, divisor);
	}
}

#endif
