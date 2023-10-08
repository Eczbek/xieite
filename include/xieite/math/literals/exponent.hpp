#ifndef XIEITE_HEADER__MATH__LITERALS__EXPONENT
#	define XIEITE_HEADER__MATH__LITERALS__EXPONENT

#	include "../../math/Exponent.hpp"

namespace xieite::math::literals {
	[[nodiscard]] constexpr auto operator""_exponent(const unsigned long long int value) noexcept {
		return xieite::math::Exponent(value);
	}

	[[nodiscard]] constexpr auto operator""_exponent(const long double value) noexcept {
		return xieite::math::Exponent(value);
	}
}

#endif
