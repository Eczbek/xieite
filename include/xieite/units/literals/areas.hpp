#ifndef XIEITE_HEADER_UNITS_LITERALS_AREAS
#	define XIEITE_HEADER_UNITS_LITERALS_AREAS

#	include "../../units/area.hpp"
#	include "../../units/convert.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_quectometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::quectometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_quectometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::quectometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_rontometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::rontometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_rontometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::rontometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_yoctometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::yoctometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_yoctometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::yoctometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_zeptometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::zeptometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_zeptometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::zeptometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_attometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::attometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_attometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::attometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_femtometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::femtometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_femtometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::femtometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_picometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::picometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_picometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::picometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_nanometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::nanometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_nanometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::nanometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_micrometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::micrometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_micrometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::micrometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_millimeters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::millimeter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_millimeters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::millimeter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_centimeters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::centimeter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_centimeters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::centimeter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_decimeters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::decimeter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_decimeters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::decimeter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_meters(const long double value) noexcept {
		return value;
	}

	[[nodiscard]] constexpr double operator""_meters(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_decameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::decameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_decameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::decameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_hectometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::hectometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_hectometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::hectometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_kilometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::kilometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_kilometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::kilometer, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_megameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::megameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_megameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::megameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_gigameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::gigameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_gigameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::gigameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_terameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::terameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_terameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::terameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_petameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::petameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_petameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::petameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_exameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::exameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_exameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::exameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_zettameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::zettameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_zettameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::zettameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_yottameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::yottameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_yottameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::yottameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_ronnameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::ronnameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_ronnameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::ronnameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_quettameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::quettameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_quettameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::quettameter, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_inches(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::inch, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_inches(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::inch, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_feet(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::foot, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_feet(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::foot, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_yards(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::yard, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_yards(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::yard, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_miles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::mile, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_miles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::mile, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_nauticalMiles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::nauticalMile, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_nauticalMiles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::nauticalMile, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_roods(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::rood, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_roods(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::rood, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_acres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::acre, xieite::units::Area::meter);
	}

	[[nodiscard]] constexpr double operator""_acres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::acre, xieite::units::Area::meter);
	}

}

#endif
