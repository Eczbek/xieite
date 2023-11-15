#ifndef XIEITE_HEADER_UNITS_LITERALS_LENGTHS
#	define XIEITE_HEADER_UNITS_LITERALS_LENGTHS

#	include "../../units/convert.hpp"
#	include "../../units/length.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_quectometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::quectometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_quectometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::quectometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_rontometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::rontometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_rontometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::rontometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_yoctometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::yoctometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_yoctometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::yoctometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_zeptometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::zeptometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_zeptometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::zeptometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_attometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::attometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_attometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::attometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_femtometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::femtometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_femtometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::femtometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_picometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::picometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_picometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::picometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_nanometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::nanometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_nanometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::nanometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_micrometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::micrometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_micrometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::micrometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_millimeters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::millimeter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_millimeters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::millimeter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_centimeters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::centimeter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_centimeters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::centimeter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_decimeters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::decimeter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_decimeters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::decimeter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_meters(const long double value) noexcept {
		return value;
	}

	[[nodiscard]] constexpr double operator""_meters(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_decameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::decameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_decameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::decameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_hectometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::hectometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_hectometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::hectometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_kilometers(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::kilometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_kilometers(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::kilometer, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_megameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::megameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_megameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::megameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_gigameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::gigameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_gigameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::gigameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_terameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::terameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_terameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::terameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_petameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::petameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_petameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::petameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_exameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::exameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_exameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::exameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_zettameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::zettameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_zettameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::zettameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_yottameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::yottameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_yottameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::yottameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_ronnameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::ronnameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_ronnameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::ronnameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_quettameters(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::quettameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_quettameters(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::quettameter, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_twips(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::twip, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_twips(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::twip, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_thous(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::thou, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_thous(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::thou, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_barleycorns(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::barleycorn, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_barleycorns(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::barleycorn, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_inches(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::inch, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_inches(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::inch, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_feet(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::foot, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_feet(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::foot, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_yards(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::yard, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_yards(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::yard, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_chains(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::chain, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_chains(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::chain, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_furlongs(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::furlong, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_furlongs(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::furlong, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_miles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::mile, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_miles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::mile, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_leagues(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::league, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_leagues(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::league, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_fathoms(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::fathom, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_fathoms(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::fathom, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_cables(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::cable, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_cables(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::cable, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_nauticalMiles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::nauticalMile, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_nauticalMiles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::nauticalMile, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_links(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::link, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_links(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::link, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_rods(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::rod, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_rods(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::rod, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_perches(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::perch, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_perches(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::perch, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_poles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::pole, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_poles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::pole, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_lugs(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::lug, xieite::units::Length::meter);
	}

	[[nodiscard]] constexpr double operator""_lugs(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::lug, xieite::units::Length::meter);
	}
}

#endif
