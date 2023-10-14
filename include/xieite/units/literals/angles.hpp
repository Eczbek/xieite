#ifndef XIEITE_HEADER_UNITS_LITERALS_ANGLES
#	define XIEITE_HEADER_UNITS_LITERALS_ANGLES

#	include "../../units/angles.hpp"
#	include "../../units/convert.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_radians(const long double value) noexcept {
		return value;
	}

	[[nodiscard]] constexpr double operator""_radians(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_degrees(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Degree, xieite::units::Radian>(value);
	}

	[[nodiscard]] constexpr double operator""_degrees(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Degree, xieite::units::Radian>(value);
	}
}

#endif
