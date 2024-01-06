#ifndef XIEITE_HEADER_MATH_LITERALS_EXPONENT
#	define XIEITE_HEADER_MATH_LITERALS_EXPONENT

#	include "../../math/exponent.hpp"

namespace xieite::math::literals::exponent {
	[[nodiscard]] constexpr auto operator""_exponent(const unsigned long long int value) noexcept {
		return xieite::math::Exponent(value);
	}

	[[nodiscard]] constexpr auto operator""_exponent(const long double value) noexcept {
		return xieite::math::Exponent(value);
	}
}

#endif
