#ifndef XIEITE_HEADER_UNITS_LITERALS_LENGTHS
#	define XIEITE_HEADER_UNITS_LITERALS_LENGTHS

#	include "../../units/convert.hpp"
#	include "../../units/lengths.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_attometers(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Attometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_attometers(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Attometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_femtometers(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Femtometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_femtometers(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Femtometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_picometers(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Picometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_picometers(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Picometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_nanometers(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Nanometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_nanometers(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Nanometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_micrometers(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Micrometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_micrometers(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Micrometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_millimeters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Millimeter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_millimeters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Millimeter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_centimeters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Centimeter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_centimeters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Centimeter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_decimeters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Decimeter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_decimeters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Decimeter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_meters(const long double value) noexcept {
		return value;
	}

	[[nodiscard]] constexpr double operator""_meters(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_decameters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Decameter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_decameters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Decameter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_hectometers(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Hectometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_hectometers(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Hectometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_kilometers(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Kilometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_kilometers(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Kilometer, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_megameters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Megameter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_megameters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Megameter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_gigameters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Gigameter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_gigameters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Gigameter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_terameters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Terameter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_terameters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Terameter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_petameters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Petameter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_petameters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Petameter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_exameters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Exameter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_exameters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Exameter, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_twips(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Twip, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_twips(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Twip, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_thous(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Thou, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_thous(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Thou, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_barleycorns(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Barleycorn, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_barleycorns(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Barleycorn, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_inches(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Inch, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_inches(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Inch, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_feet(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Foot, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_feet(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Foot, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_yards(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Yard, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_yards(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Yard, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_chains(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Chain, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_chains(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Chain, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_furlongs(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Furlong, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_furlongs(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Furlong, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_miles(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Mile, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_miles(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Mile, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_leagues(const long double value) noexcept {
		return xieite::units::convert<xieite::units::League, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_leagues(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::League, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_fathoms(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Fathom, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_fathoms(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Fathom, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_cables(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Cable, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_cables(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Cable, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_nauticalMiles(const long double value) noexcept {
		return xieite::units::convert<xieite::units::NauticalMile, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_nauticalMiles(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::NauticalMile, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_links(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Link, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_links(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Link, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_rods(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Rod, xieite::units::Meter>(value);
	}

	[[nodiscard]] constexpr double operator""_rods(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Rod, xieite::units::Meter>(value);
	}
}

#endif
