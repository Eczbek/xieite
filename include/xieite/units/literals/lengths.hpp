#ifndef XIEITE_HEADER_UNITS_LITERALS_LENGTHS
#	define XIEITE_HEADER_UNITS_LITERALS_LENGTHS

#	include "../../units/lengths.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_attometers(const long double value) noexcept {
		return value * xieite::units::Attometer::num / xieite::units::Attometer::den;
	}

	[[nodiscard]] constexpr double operator""_attometers(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Attometer::num / xieite::units::Attometer::den;
	}

	[[nodiscard]] constexpr double operator""_femtometers(const long double value) noexcept {
		return value * xieite::units::Femtometer::num / xieite::units::Femtometer::den;
	}

	[[nodiscard]] constexpr double operator""_femtometers(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Femtometer::num / xieite::units::Femtometer::den;
	}

	[[nodiscard]] constexpr double operator""_picometers(const long double value) noexcept {
		return value * xieite::units::Picometer::num / xieite::units::Picometer::den;
	}

	[[nodiscard]] constexpr double operator""_picometers(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Picometer::num / xieite::units::Picometer::den;
	}

	[[nodiscard]] constexpr double operator""_nanometers(const long double value) noexcept {
		return value * xieite::units::Nanometer::num / xieite::units::Nanometer::den;
	}

	[[nodiscard]] constexpr double operator""_nanometers(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Nanometer::num / xieite::units::Nanometer::den;
	}

	[[nodiscard]] constexpr double operator""_micrometers(const long double value) noexcept {
		return value * xieite::units::Micrometer::num / xieite::units::Micrometer::den;
	}

	[[nodiscard]] constexpr double operator""_micrometers(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Micrometer::num / xieite::units::Micrometer::den;
	}

	[[nodiscard]] constexpr double operator""_millimeters(const long double value) noexcept {
		return value * xieite::units::Millimeter::num / xieite::units::Millimeter::den;
	}

	[[nodiscard]] constexpr double operator""_millimeters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Millimeter::num / xieite::units::Millimeter::den;
	}

	[[nodiscard]] constexpr double operator""_centimeters(const long double value) noexcept {
		return value * xieite::units::Centimeter::num / xieite::units::Centimeter::den;
	}

	[[nodiscard]] constexpr double operator""_centimeters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Centimeter::num / xieite::units::Centimeter::den;
	}

	[[nodiscard]] constexpr double operator""_decimeters(const long double value) noexcept {
		return value * xieite::units::Decimeter::num / xieite::units::Decimeter::den;
	}

	[[nodiscard]] constexpr double operator""_decimeters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Decimeter::num / xieite::units::Decimeter::den;
	}

	[[nodiscard]] constexpr double operator""_meters(const long double value) noexcept {
		return value * xieite::units::Meter::num / xieite::units::Meter::den;
	}

	[[nodiscard]] constexpr double operator""_meters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Meter::num / xieite::units::Meter::den;
	}

	[[nodiscard]] constexpr double operator""_decameters(const long double value) noexcept {
		return value * xieite::units::Decameter::num / xieite::units::Decameter::den;
	}

	[[nodiscard]] constexpr double operator""_decameters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Decameter::num / xieite::units::Decameter::den;
	}

	[[nodiscard]] constexpr double operator""_hectometers(const long double value) noexcept {
		return value * xieite::units::Hectometer::num / xieite::units::Hectometer::den;
	}

	[[nodiscard]] constexpr double operator""_hectometers(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Hectometer::num / xieite::units::Hectometer::den;
	}

	[[nodiscard]] constexpr double operator""_kilometers(const long double value) noexcept {
		return value * xieite::units::Kilometer::num / xieite::units::Kilometer::den;
	}

	[[nodiscard]] constexpr double operator""_kilometers(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Kilometer::num / xieite::units::Kilometer::den;
	}

	[[nodiscard]] constexpr double operator""_megameters(const long double value) noexcept {
		return value * xieite::units::Megameter::num / xieite::units::Megameter::den;
	}

	[[nodiscard]] constexpr double operator""_megameters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Megameter::num / xieite::units::Megameter::den;
	}

	[[nodiscard]] constexpr double operator""_gigameters(const long double value) noexcept {
		return value * xieite::units::Gigameter::num / xieite::units::Gigameter::den;
	}

	[[nodiscard]] constexpr double operator""_gigameters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Gigameter::num / xieite::units::Gigameter::den;
	}

	[[nodiscard]] constexpr double operator""_terameters(const long double value) noexcept {
		return value * xieite::units::Terameter::num / xieite::units::Terameter::den;
	}

	[[nodiscard]] constexpr double operator""_terameters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Terameter::num / xieite::units::Terameter::den;
	}

	[[nodiscard]] constexpr double operator""_petameters(const long double value) noexcept {
		return value * xieite::units::Petameter::num / xieite::units::Petameter::den;
	}

	[[nodiscard]] constexpr double operator""_petameters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Petameter::num / xieite::units::Petameter::den;
	}

	[[nodiscard]] constexpr double operator""_exameters(const long double value) noexcept {
		return value * xieite::units::Exameter::num / xieite::units::Exameter::den;
	}

	[[nodiscard]] constexpr double operator""_exameters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Exameter::num / xieite::units::Exameter::den;
	}

	[[nodiscard]] constexpr double operator""_twips(const long double value) noexcept {
		return value * xieite::units::Twip::num / xieite::units::Twip::den;
	}

	[[nodiscard]] constexpr double operator""_twips(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Twip::num / xieite::units::Twip::den;
	}

	[[nodiscard]] constexpr double operator""_thous(const long double value) noexcept {
		return value * xieite::units::Thou::num / xieite::units::Thou::den;
	}

	[[nodiscard]] constexpr double operator""_thous(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Thou::num / xieite::units::Thou::den;
	}

	[[nodiscard]] constexpr double operator""_barleycorns(const long double value) noexcept {
		return value * xieite::units::Barleycorn::num / xieite::units::Barleycorn::den;
	}

	[[nodiscard]] constexpr double operator""_barleycorns(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Barleycorn::num / xieite::units::Barleycorn::den;
	}

	[[nodiscard]] constexpr double operator""_inchs(const long double value) noexcept {
		return value * xieite::units::Inch::num / xieite::units::Inch::den;
	}

	[[nodiscard]] constexpr double operator""_inchs(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Inch::num / xieite::units::Inch::den;
	}

	[[nodiscard]] constexpr double operator""_foots(const long double value) noexcept {
		return value * xieite::units::Foot::num / xieite::units::Foot::den;
	}

	[[nodiscard]] constexpr double operator""_foots(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Foot::num / xieite::units::Foot::den;
	}

	[[nodiscard]] constexpr double operator""_yards(const long double value) noexcept {
		return value * xieite::units::Yard::num / xieite::units::Yard::den;
	}

	[[nodiscard]] constexpr double operator""_yards(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Yard::num / xieite::units::Yard::den;
	}

	[[nodiscard]] constexpr double operator""_chains(const long double value) noexcept {
		return value * xieite::units::Chain::num / xieite::units::Chain::den;
	}

	[[nodiscard]] constexpr double operator""_chains(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Chain::num / xieite::units::Chain::den;
	}

	[[nodiscard]] constexpr double operator""_furlongs(const long double value) noexcept {
		return value * xieite::units::Furlong::num / xieite::units::Furlong::den;
	}

	[[nodiscard]] constexpr double operator""_furlongs(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Furlong::num / xieite::units::Furlong::den;
	}

	[[nodiscard]] constexpr double operator""_miles(const long double value) noexcept {
		return value * xieite::units::Mile::num / xieite::units::Mile::den;
	}

	[[nodiscard]] constexpr double operator""_miles(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Mile::num / xieite::units::Mile::den;
	}

	[[nodiscard]] constexpr double operator""_leagues(const long double value) noexcept {
		return value * xieite::units::League::num / xieite::units::League::den;
	}

	[[nodiscard]] constexpr double operator""_leagues(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::League::num / xieite::units::League::den;
	}

	[[nodiscard]] constexpr double operator""_fathoms(const long double value) noexcept {
		return value * xieite::units::Fathom::num / xieite::units::Fathom::den;
	}

	[[nodiscard]] constexpr double operator""_fathoms(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Fathom::num / xieite::units::Fathom::den;
	}

	[[nodiscard]] constexpr double operator""_cables(const long double value) noexcept {
		return value * xieite::units::Cable::num / xieite::units::Cable::den;
	}

	[[nodiscard]] constexpr double operator""_cables(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Cable::num / xieite::units::Cable::den;
	}

	[[nodiscard]] constexpr double operator""_nauticalMiles(const long double value) noexcept {
		return value * xieite::units::NauticalMile::num / xieite::units::NauticalMile::den;
	}

	[[nodiscard]] constexpr double operator""_nauticalMiles(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::NauticalMile::num / xieite::units::NauticalMile::den;
	}

	[[nodiscard]] constexpr double operator""_links(const long double value) noexcept {
		return value * xieite::units::Link::num / xieite::units::Link::den;
	}

	[[nodiscard]] constexpr double operator""_links(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Link::num / xieite::units::Link::den;
	}

	[[nodiscard]] constexpr double operator""_rods(const long double value) noexcept {
		return value * xieite::units::Rod::num / xieite::units::Rod::den;
	}

	[[nodiscard]] constexpr double operator""_rods(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Rod::num / xieite::units::Rod::den;
	}
}

#endif
