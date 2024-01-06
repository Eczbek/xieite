#ifndef XIEITE_HEADER_UNITS_LITERALS_TEMPERATURES
#	define XIEITE_HEADER_UNITS_LITERALS_TEMPERATURES

#	include "../../units/convert.hpp"
#	include "../../units/temperature.hpp"

namespace xieite::units::literals::temperatures {
	[[nodiscard]] constexpr double operator""_kelvin(const long double value) noexcept {
		return value;
	}

	[[nodiscard]] constexpr double operator""_kelvin(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_celsius(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Temperature::celsius, xieite::units::Temperature::kelvin);
	}

	[[nodiscard]] constexpr double operator""_celsius(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Temperature::celsius, xieite::units::Temperature::kelvin);
	}

	[[nodiscard]] constexpr double operator""_fahrenheit(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Temperature::fahrenheit, xieite::units::Temperature::kelvin);
	}

	[[nodiscard]] constexpr double operator""_fahrenheit(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Temperature::fahrenheit, xieite::units::Temperature::kelvin);
	}

	[[nodiscard]] constexpr double operator""_rankine(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Temperature::rankine, xieite::units::Temperature::kelvin);
	}

	[[nodiscard]] constexpr double operator""_rankine(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Temperature::rankine, xieite::units::Temperature::kelvin);
	}
}

#endif
