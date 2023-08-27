#ifndef XIEITE_HEADER__MATH__MODULO
#	define XIEITE_HEADER__MATH__MODULO

#	include <cmath>
#	include "../concepts/Arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	constexpr Arithmetic modulo(const Arithmetic dividend, const Arithmetic divisor) noexcept {
		return std::fmod(std::fmod(dividend, divisor) + divisor, divisor);
	}
}

#endif
