export module xieite:literals.units;

import :units.angle;
import :units.area;
import :units.length;
import :units.temperature;
import :units.volume;

export namespace xieite::literals::units {
	[[nodiscard]] constexpr xieite::units::Quectometer operator""_quectometers(const unsigned long long int value) noexcept {
		return xieite::units::Quectometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quectometer operator""_quectometers(const long double value) noexcept {
		return xieite::units::Quectometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Rontometer operator""_rontometers(const unsigned long long int value) noexcept {
		return xieite::units::Rontometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Rontometer operator""_rontometers(const long double value) noexcept {
		return xieite::units::Rontometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yoctometer operator""_yoctometers(const unsigned long long int value) noexcept {
		return xieite::units::Yoctometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yoctometer operator""_yoctometers(const long double value) noexcept {
		return xieite::units::Yoctometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zeptometer operator""_zeptometers(const unsigned long long int value) noexcept {
		return xieite::units::Zeptometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zeptometer operator""_zeptometers(const long double value) noexcept {
		return xieite::units::Zeptometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Attometer operator""_attometers(const unsigned long long int value) noexcept {
		return xieite::units::Attometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Attometer operator""_attometers(const long double value) noexcept {
		return xieite::units::Attometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Femtometer operator""_femtometers(const unsigned long long int value) noexcept {
		return xieite::units::Femtometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Femtometer operator""_femtometers(const long double value) noexcept {
		return xieite::units::Femtometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Picometer operator""_picometers(const unsigned long long int value) noexcept {
		return xieite::units::Picometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Picometer operator""_picometers(const long double value) noexcept {
		return xieite::units::Picometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Nanometer operator""_nanometers(const unsigned long long int value) noexcept {
		return xieite::units::Nanometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Nanometer operator""_nanometers(const long double value) noexcept {
		return xieite::units::Nanometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Micrometer operator""_micrometers(const unsigned long long int value) noexcept {
		return xieite::units::Micrometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Micrometer operator""_micrometers(const long double value) noexcept {
		return xieite::units::Micrometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Millimeter operator""_millimeters(const unsigned long long int value) noexcept {
		return xieite::units::Millimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Millimeter operator""_millimeters(const long double value) noexcept {
		return xieite::units::Millimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Centimeter operator""_centimeters(const unsigned long long int value) noexcept {
		return xieite::units::Centimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Centimeter operator""_centimeters(const long double value) noexcept {
		return xieite::units::Centimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decimeter operator""_decimeters(const unsigned long long int value) noexcept {
		return xieite::units::Decimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decimeter operator""_decimeters(const long double value) noexcept {
		return xieite::units::Decimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Meter operator""_meters(const unsigned long long int value) noexcept {
		return xieite::units::Meter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Meter operator""_meters(const long double value) noexcept {
		return xieite::units::Meter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decameter operator""_decameters(const unsigned long long int value) noexcept {
		return xieite::units::Decameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decameter operator""_decameters(const long double value) noexcept {
		return xieite::units::Decameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Hectometer operator""_hectometers(const unsigned long long int value) noexcept {
		return xieite::units::Hectometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Hectometer operator""_hectometers(const long double value) noexcept {
		return xieite::units::Hectometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Kilometer operator""_kilometers(const unsigned long long int value) noexcept {
		return xieite::units::Kilometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Kilometer operator""_kilometers(const long double value) noexcept {
		return xieite::units::Kilometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Megameter operator""_megameters(const unsigned long long int value) noexcept {
		return xieite::units::Megameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Megameter operator""_megameters(const long double value) noexcept {
		return xieite::units::Megameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Gigameter operator""_gigameters(const unsigned long long int value) noexcept {
		return xieite::units::Gigameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Gigameter operator""_gigameters(const long double value) noexcept {
		return xieite::units::Gigameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Terameter operator""_terameters(const unsigned long long int value) noexcept {
		return xieite::units::Terameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Terameter operator""_terameters(const long double value) noexcept {
		return xieite::units::Terameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Petameter operator""_petameters(const unsigned long long int value) noexcept {
		return xieite::units::Petameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Petameter operator""_petameters(const long double value) noexcept {
		return xieite::units::Petameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Exameter operator""_exameters(const unsigned long long int value) noexcept {
		return xieite::units::Exameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Exameter operator""_exameters(const long double value) noexcept {
		return xieite::units::Exameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zettameter operator""_zettameters(const unsigned long long int value) noexcept {
		return xieite::units::Zettameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zettameter operator""_zettameters(const long double value) noexcept {
		return xieite::units::Zettameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yottameter operator""_yottameters(const unsigned long long int value) noexcept {
		return xieite::units::Yottameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yottameter operator""_yottameters(const long double value) noexcept {
		return xieite::units::Yottameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Ronnameter operator""_ronnameters(const unsigned long long int value) noexcept {
		return xieite::units::Ronnameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Ronnameter operator""_ronnameters(const long double value) noexcept {
		return xieite::units::Ronnameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quettameter operator""_quettameters(const unsigned long long int value) noexcept {
		return xieite::units::Quettameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quettameter operator""_quettameters(const long double value) noexcept {
		return xieite::units::Quettameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Twip operator""_twips(const unsigned long long int value) noexcept {
		return xieite::units::Twip(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Twip operator""_twips(const long double value) noexcept {
		return xieite::units::Twip(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Thou operator""_thous(const unsigned long long int value) noexcept {
		return xieite::units::Thou(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Thou operator""_thous(const long double value) noexcept {
		return xieite::units::Thou(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Barleycorn operator""_barleycorns(const unsigned long long int value) noexcept {
		return xieite::units::Barleycorn(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Barleycorn operator""_barleycorns(const long double value) noexcept {
		return xieite::units::Barleycorn(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Inch operator""_inches(const unsigned long long int value) noexcept {
		return xieite::units::Inch(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Inch operator""_inches(const long double value) noexcept {
		return xieite::units::Inch(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Foot operator""_feet(const unsigned long long int value) noexcept {
		return xieite::units::Foot(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Foot operator""_feet(const long double value) noexcept {
		return xieite::units::Foot(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yard operator""_yards(const unsigned long long int value) noexcept {
		return xieite::units::Yard(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yard operator""_yards(const long double value) noexcept {
		return xieite::units::Yard(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Chain operator""_chains(const unsigned long long int value) noexcept {
		return xieite::units::Chain(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Chain operator""_chains(const long double value) noexcept {
		return xieite::units::Chain(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Furlong operator""_furlongs(const unsigned long long int value) noexcept {
		return xieite::units::Furlong(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Furlong operator""_furlongs(const long double value) noexcept {
		return xieite::units::Furlong(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Mile operator""_miles(const unsigned long long int value) noexcept {
		return xieite::units::Mile(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Mile operator""_miles(const long double value) noexcept {
		return xieite::units::Mile(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::League operator""_leagues(const unsigned long long int value) noexcept {
		return xieite::units::League(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::League operator""_leagues(const long double value) noexcept {
		return xieite::units::League(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Fathom operator""_fathoms(const unsigned long long int value) noexcept {
		return xieite::units::Fathom(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Fathom operator""_fathoms(const long double value) noexcept {
		return xieite::units::Fathom(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Cable operator""_cables(const unsigned long long int value) noexcept {
		return xieite::units::Cable(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Cable operator""_cables(const long double value) noexcept {
		return xieite::units::Cable(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::NauticalMile operator""_nauticalMiles(const unsigned long long int value) noexcept {
		return xieite::units::NauticalMile(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::NauticalMile operator""_nauticalMiles(const long double value) noexcept {
		return xieite::units::NauticalMile(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Link operator""_links(const unsigned long long int value) noexcept {
		return xieite::units::Link(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Link operator""_links(const long double value) noexcept {
		return xieite::units::Link(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Rod operator""_rods(const unsigned long long int value) noexcept {
		return xieite::units::Rod(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Rod operator""_rods(const long double value) noexcept {
		return xieite::units::Rod(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Perch operator""_perches(const unsigned long long int value) noexcept {
		return xieite::units::Perch(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Perch operator""_perches(const long double value) noexcept {
		return xieite::units::Perch(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Pole operator""_poles(const unsigned long long int value) noexcept {
		return xieite::units::Pole(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Pole operator""_poles(const long double value) noexcept {
		return xieite::units::Pole(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Lug operator""_lugs(const unsigned long long int value) noexcept {
		return xieite::units::Lug(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Lug operator""_lugs(const long double value) noexcept {
		return xieite::units::Lug(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareQuectometer operator""_squareQuectometers(const unsigned long long int value) noexcept {
		return xieite::units::SquareQuectometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareQuectometer operator""_squareQuectometers(const long double value) noexcept {
		return xieite::units::SquareQuectometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareRontometer operator""_squareRontometers(const unsigned long long int value) noexcept {
		return xieite::units::SquareRontometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareRontometer operator""_squareRontometers(const long double value) noexcept {
		return xieite::units::SquareRontometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareYoctometer operator""_squareYoctometers(const unsigned long long int value) noexcept {
		return xieite::units::SquareYoctometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareYoctometer operator""_squareYoctometers(const long double value) noexcept {
		return xieite::units::SquareYoctometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareZeptometer operator""_squareZeptometers(const unsigned long long int value) noexcept {
		return xieite::units::SquareZeptometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareZeptometer operator""_squareZeptometers(const long double value) noexcept {
		return xieite::units::SquareZeptometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareAttometer operator""_squareAttometers(const unsigned long long int value) noexcept {
		return xieite::units::SquareAttometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareAttometer operator""_squareAttometers(const long double value) noexcept {
		return xieite::units::SquareAttometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareFemtometer operator""_squareFemtometers(const unsigned long long int value) noexcept {
		return xieite::units::SquareFemtometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareFemtometer operator""_squareFemtometers(const long double value) noexcept {
		return xieite::units::SquareFemtometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquarePicometer operator""_squarePicometers(const unsigned long long int value) noexcept {
		return xieite::units::SquarePicometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquarePicometer operator""_squarePicometers(const long double value) noexcept {
		return xieite::units::SquarePicometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareNanometer operator""_squareNanometers(const unsigned long long int value) noexcept {
		return xieite::units::SquareNanometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareNanometer operator""_squareNanometers(const long double value) noexcept {
		return xieite::units::SquareNanometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMicrometer operator""_squareMicrometers(const unsigned long long int value) noexcept {
		return xieite::units::SquareMicrometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMicrometer operator""_squareMicrometers(const long double value) noexcept {
		return xieite::units::SquareMicrometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMillimeter operator""_squareMillimeters(const unsigned long long int value) noexcept {
		return xieite::units::SquareMillimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMillimeter operator""_squareMillimeters(const long double value) noexcept {
		return xieite::units::SquareMillimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareCentimeter operator""_squareCentimeters(const unsigned long long int value) noexcept {
		return xieite::units::SquareCentimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareCentimeter operator""_squareCentimeters(const long double value) noexcept {
		return xieite::units::SquareCentimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareDecimeter operator""_squareDecimeters(const unsigned long long int value) noexcept {
		return xieite::units::SquareDecimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareDecimeter operator""_squareDecimeters(const long double value) noexcept {
		return xieite::units::SquareDecimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMeter operator""_squareMeters(const unsigned long long int value) noexcept {
		return xieite::units::SquareMeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMeter operator""_squareMeters(const long double value) noexcept {
		return xieite::units::SquareMeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareDecameter operator""_squareDecameters(const unsigned long long int value) noexcept {
		return xieite::units::SquareDecameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareDecameter operator""_squareDecameters(const long double value) noexcept {
		return xieite::units::SquareDecameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareHectometer operator""_squareHectometers(const unsigned long long int value) noexcept {
		return xieite::units::SquareHectometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareHectometer operator""_squareHectometers(const long double value) noexcept {
		return xieite::units::SquareHectometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareKilometer operator""_squareKilometers(const unsigned long long int value) noexcept {
		return xieite::units::SquareKilometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareKilometer operator""_squareKilometers(const long double value) noexcept {
		return xieite::units::SquareKilometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMegameter operator""_squareMegameters(const unsigned long long int value) noexcept {
		return xieite::units::SquareMegameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMegameter operator""_squareMegameters(const long double value) noexcept {
		return xieite::units::SquareMegameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareGigameter operator""_squareGigameters(const unsigned long long int value) noexcept {
		return xieite::units::SquareGigameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareGigameter operator""_squareGigameters(const long double value) noexcept {
		return xieite::units::SquareGigameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareTerameter operator""_squareTerameters(const unsigned long long int value) noexcept {
		return xieite::units::SquareTerameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareTerameter operator""_squareTerameters(const long double value) noexcept {
		return xieite::units::SquareTerameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquarePetameter operator""_squarePetameters(const unsigned long long int value) noexcept {
		return xieite::units::SquarePetameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquarePetameter operator""_squarePetameters(const long double value) noexcept {
		return xieite::units::SquarePetameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareExameter operator""_squareExameters(const unsigned long long int value) noexcept {
		return xieite::units::SquareExameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareExameter operator""_squareExameters(const long double value) noexcept {
		return xieite::units::SquareExameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareZettameter operator""_squareZettameters(const unsigned long long int value) noexcept {
		return xieite::units::SquareZettameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareZettameter operator""_squareZettameters(const long double value) noexcept {
		return xieite::units::SquareZettameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareYottameter operator""_squareYottameters(const unsigned long long int value) noexcept {
		return xieite::units::SquareYottameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareYottameter operator""_squareYottameters(const long double value) noexcept {
		return xieite::units::SquareYottameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareRonnameter operator""_squareRonnameters(const unsigned long long int value) noexcept {
		return xieite::units::SquareRonnameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareRonnameter operator""_squareRonnameters(const long double value) noexcept {
		return xieite::units::SquareRonnameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareQuettameter operator""_squareQuettameters(const unsigned long long int value) noexcept {
		return xieite::units::SquareQuettameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareQuettameter operator""_squareQuettameters(const long double value) noexcept {
		return xieite::units::SquareQuettameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareInch operator""_squareInches(const unsigned long long int value) noexcept {
		return xieite::units::SquareInch(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareInch operator""_squareInches(const long double value) noexcept {
		return xieite::units::SquareInch(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareFoot operator""_squareFeet(const unsigned long long int value) noexcept {
		return xieite::units::SquareFoot(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareFoot operator""_squareFeet(const long double value) noexcept {
		return xieite::units::SquareFoot(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareYard operator""_squareYards(const unsigned long long int value) noexcept {
		return xieite::units::SquareYard(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareYard operator""_squareYards(const long double value) noexcept {
		return xieite::units::SquareYard(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMile operator""_squareMiles(const unsigned long long int value) noexcept {
		return xieite::units::SquareMile(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMile operator""_squareMiles(const long double value) noexcept {
		return xieite::units::SquareMile(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareRood operator""_roods(const unsigned long long int value) noexcept {
		return xieite::units::SquareRood(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareRood operator""_roods(const long double value) noexcept {
		return xieite::units::SquareRood(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Acre operator""_acres(const unsigned long long int value) noexcept {
		return xieite::units::Acre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Acre operator""_acres(const long double value) noexcept {
		return xieite::units::Acre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decimilliare operator""_decimilliares(const unsigned long long int value) noexcept {
		return xieite::units::Decimilliare(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decimilliare operator""_decimilliares(const long double value) noexcept {
		return xieite::units::Decimilliare(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Centiare operator""_centiare(const unsigned long long int value) noexcept {
		return xieite::units::Centiare(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Centiare operator""_centiare(const long double value) noexcept {
		return xieite::units::Centiare(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Deciare operator""_deciares(const unsigned long long int value) noexcept {
		return xieite::units::Deciare(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Deciare operator""_deciares(const long double value) noexcept {
		return xieite::units::Deciare(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Are operator""_ares(const unsigned long long int value) noexcept {
		return xieite::units::Are(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Are operator""_ares(const long double value) noexcept {
		return xieite::units::Are(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decare operator""_decares(const unsigned long long int value) noexcept {
		return xieite::units::Decare(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decare operator""_decares(const long double value) noexcept {
		return xieite::units::Decare(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Hectare operator""_hectares(const unsigned long long int value) noexcept {
		return xieite::units::Hectare(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Hectare operator""_hectares(const long double value) noexcept {
		return xieite::units::Hectare(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicQuectometer operator""_cubicQuectometers(const unsigned long long int value) noexcept {
		return xieite::units::CubicQuectometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicQuectometer operator""_cubicQuectometers(const long double value) noexcept {
		return xieite::units::CubicQuectometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicRontometer operator""_cubicRontometers(const unsigned long long int value) noexcept {
		return xieite::units::CubicRontometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicRontometer operator""_cubicRontometers(const long double value) noexcept {
		return xieite::units::CubicRontometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicYoctometer operator""_cubicYoctometers(const unsigned long long int value) noexcept {
		return xieite::units::CubicYoctometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicYoctometer operator""_cubicYoctometers(const long double value) noexcept {
		return xieite::units::CubicYoctometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicZeptometer operator""_cubicZeptometers(const unsigned long long int value) noexcept {
		return xieite::units::CubicZeptometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicZeptometer operator""_cubicZeptometers(const long double value) noexcept {
		return xieite::units::CubicZeptometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicAttometer operator""_cubicAttometers(const unsigned long long int value) noexcept {
		return xieite::units::CubicAttometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicAttometer operator""_cubicAttometers(const long double value) noexcept {
		return xieite::units::CubicAttometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicFemtometer operator""_cubicFemtometers(const unsigned long long int value) noexcept {
		return xieite::units::CubicFemtometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicFemtometer operator""_cubicFemtometers(const long double value) noexcept {
		return xieite::units::CubicFemtometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicPicometer operator""_cubicPicometers(const unsigned long long int value) noexcept {
		return xieite::units::CubicPicometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicPicometer operator""_cubicPicometers(const long double value) noexcept {
		return xieite::units::CubicPicometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicNanometer operator""_cubicNanometers(const unsigned long long int value) noexcept {
		return xieite::units::CubicNanometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicNanometer operator""_cubicNanometers(const long double value) noexcept {
		return xieite::units::CubicNanometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMicrometer operator""_cubicMicrometers(const unsigned long long int value) noexcept {
		return xieite::units::CubicMicrometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMicrometer operator""_cubicMicrometers(const long double value) noexcept {
		return xieite::units::CubicMicrometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMillimeter operator""_cubicMillimeters(const unsigned long long int value) noexcept {
		return xieite::units::CubicMillimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMillimeter operator""_cubicMillimeters(const long double value) noexcept {
		return xieite::units::CubicMillimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicCentimeter operator""_cubicCentimeters(const unsigned long long int value) noexcept {
		return xieite::units::CubicCentimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicCentimeter operator""_cubicCentimeters(const long double value) noexcept {
		return xieite::units::CubicCentimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicDecimeter operator""_cubicDecimeters(const unsigned long long int value) noexcept {
		return xieite::units::CubicDecimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicDecimeter operator""_cubicDecimeters(const long double value) noexcept {
		return xieite::units::CubicDecimeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMeter operator""_cubicMeters(const unsigned long long int value) noexcept {
		return xieite::units::CubicMeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMeter operator""_cubicMeters(const long double value) noexcept {
		return xieite::units::CubicMeter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicDecameter operator""_cubicDecameters(const unsigned long long int value) noexcept {
		return xieite::units::CubicDecameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicDecameter operator""_cubicDecameters(const long double value) noexcept {
		return xieite::units::CubicDecameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicHectometer operator""_cubicHectometers(const unsigned long long int value) noexcept {
		return xieite::units::CubicHectometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicHectometer operator""_cubicHectometers(const long double value) noexcept {
		return xieite::units::CubicHectometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicKilometer operator""_cubicKilometers(const unsigned long long int value) noexcept {
		return xieite::units::CubicKilometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicKilometer operator""_cubicKilometers(const long double value) noexcept {
		return xieite::units::CubicKilometer(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMegameter operator""_cubicMegameters(const unsigned long long int value) noexcept {
		return xieite::units::CubicMegameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMegameter operator""_cubicMegameters(const long double value) noexcept {
		return xieite::units::CubicMegameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicGigameter operator""_cubicGigameters(const unsigned long long int value) noexcept {
		return xieite::units::CubicGigameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicGigameter operator""_cubicGigameters(const long double value) noexcept {
		return xieite::units::CubicGigameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicTerameter operator""_cubicTerameters(const unsigned long long int value) noexcept {
		return xieite::units::CubicTerameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicTerameter operator""_cubicTerameters(const long double value) noexcept {
		return xieite::units::CubicTerameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicPetameter operator""_cubicPetameters(const unsigned long long int value) noexcept {
		return xieite::units::CubicPetameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicPetameter operator""_cubicPetameters(const long double value) noexcept {
		return xieite::units::CubicPetameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicExameter operator""_cubicExameters(const unsigned long long int value) noexcept {
		return xieite::units::CubicExameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicExameter operator""_cubicExameters(const long double value) noexcept {
		return xieite::units::CubicExameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicZettameter operator""_cubicZettameters(const unsigned long long int value) noexcept {
		return xieite::units::CubicZettameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicZettameter operator""_cubicZettameters(const long double value) noexcept {
		return xieite::units::CubicZettameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicYottameter operator""_cubicYottameters(const unsigned long long int value) noexcept {
		return xieite::units::CubicYottameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicYottameter operator""_cubicYottameters(const long double value) noexcept {
		return xieite::units::CubicYottameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicRonnameter operator""_cubicRonnameters(const unsigned long long int value) noexcept {
		return xieite::units::CubicRonnameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicRonnameter operator""_cubicRonnameters(const long double value) noexcept {
		return xieite::units::CubicRonnameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicQuettameter operator""_cubicQuettameters(const unsigned long long int value) noexcept {
		return xieite::units::CubicQuettameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicQuettameter operator""_cubicQuettameters(const long double value) noexcept {
		return xieite::units::CubicQuettameter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicInch operator""_cubicInches(const unsigned long long int value) noexcept {
		return xieite::units::CubicInch(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicInch operator""_cubicInches(const long double value) noexcept {
		return xieite::units::CubicInch(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicFoot operator""_cubicFeet(const unsigned long long int value) noexcept {
		return xieite::units::CubicFoot(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicFoot operator""_cubicFeet(const long double value) noexcept {
		return xieite::units::CubicFoot(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicYard operator""_cubicYards(const unsigned long long int value) noexcept {
		return xieite::units::CubicYard(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicYard operator""_cubicYards(const long double value) noexcept {
		return xieite::units::CubicYard(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMile operator""_cubicMiles(const unsigned long long int value) noexcept {
		return xieite::units::CubicMile(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMile operator""_cubicMiles(const long double value) noexcept {
		return xieite::units::CubicMile(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quectoliter operator""_quectoliters(const unsigned long long int value) noexcept {
		return xieite::units::Quectoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quectoliter operator""_quectoliters(const long double value) noexcept {
		return xieite::units::Quectoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Rontoliter operator""_rontoliters(const unsigned long long int value) noexcept {
		return xieite::units::Rontoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Rontoliter operator""_rontoliters(const long double value) noexcept {
		return xieite::units::Rontoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yoctoliter operator""_yoctoliters(const unsigned long long int value) noexcept {
		return xieite::units::Yoctoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yoctoliter operator""_yoctoliters(const long double value) noexcept {
		return xieite::units::Yoctoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zeptoliter operator""_zeptoliters(const unsigned long long int value) noexcept {
		return xieite::units::Zeptoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zeptoliter operator""_zeptoliters(const long double value) noexcept {
		return xieite::units::Zeptoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Attoliter operator""_attoliters(const unsigned long long int value) noexcept {
		return xieite::units::Attoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Attoliter operator""_attoliters(const long double value) noexcept {
		return xieite::units::Attoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Femtoliter operator""_femtoliters(const unsigned long long int value) noexcept {
		return xieite::units::Femtoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Femtoliter operator""_femtoliters(const long double value) noexcept {
		return xieite::units::Femtoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Picoliter operator""_picoliters(const unsigned long long int value) noexcept {
		return xieite::units::Picoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Picoliter operator""_picoliters(const long double value) noexcept {
		return xieite::units::Picoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Nanoliter operator""_nanoliters(const unsigned long long int value) noexcept {
		return xieite::units::Nanoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Nanoliter operator""_nanoliters(const long double value) noexcept {
		return xieite::units::Nanoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Microliter operator""_microliters(const unsigned long long int value) noexcept {
		return xieite::units::Microliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Microliter operator""_microliters(const long double value) noexcept {
		return xieite::units::Microliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Milliliter operator""_milliliters(const unsigned long long int value) noexcept {
		return xieite::units::Milliliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Milliliter operator""_milliliters(const long double value) noexcept {
		return xieite::units::Milliliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Centiliter operator""_centiliters(const unsigned long long int value) noexcept {
		return xieite::units::Centiliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Centiliter operator""_centiliters(const long double value) noexcept {
		return xieite::units::Centiliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Deciliter operator""_deciliters(const unsigned long long int value) noexcept {
		return xieite::units::Deciliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Deciliter operator""_deciliters(const long double value) noexcept {
		return xieite::units::Deciliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Liter operator""_liters(const unsigned long long int value) noexcept {
		return xieite::units::Liter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Liter operator""_liters(const long double value) noexcept {
		return xieite::units::Liter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decaliter operator""_decaliters(const unsigned long long int value) noexcept {
		return xieite::units::Decaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decaliter operator""_decaliters(const long double value) noexcept {
		return xieite::units::Decaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Hectoliter operator""_hectoliters(const unsigned long long int value) noexcept {
		return xieite::units::Hectoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Hectoliter operator""_hectoliters(const long double value) noexcept {
		return xieite::units::Hectoliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Kiloliter operator""_kiloliters(const unsigned long long int value) noexcept {
		return xieite::units::Kiloliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Kiloliter operator""_kiloliters(const long double value) noexcept {
		return xieite::units::Kiloliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Megaliter operator""_megaliters(const unsigned long long int value) noexcept {
		return xieite::units::Megaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Megaliter operator""_megaliters(const long double value) noexcept {
		return xieite::units::Megaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Gigaliter operator""_gigaliters(const unsigned long long int value) noexcept {
		return xieite::units::Gigaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Gigaliter operator""_gigaliters(const long double value) noexcept {
		return xieite::units::Gigaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Teraliter operator""_teraliters(const unsigned long long int value) noexcept {
		return xieite::units::Teraliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Teraliter operator""_teraliters(const long double value) noexcept {
		return xieite::units::Teraliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Petaliter operator""_petaliters(const unsigned long long int value) noexcept {
		return xieite::units::Petaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Petaliter operator""_petaliters(const long double value) noexcept {
		return xieite::units::Petaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Exaliter operator""_exaliters(const unsigned long long int value) noexcept {
		return xieite::units::Exaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Exaliter operator""_exaliters(const long double value) noexcept {
		return xieite::units::Exaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zettaliter operator""_zettaliters(const unsigned long long int value) noexcept {
		return xieite::units::Zettaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zettaliter operator""_zettaliters(const long double value) noexcept {
		return xieite::units::Zettaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yottaliter operator""_yottaliters(const unsigned long long int value) noexcept {
		return xieite::units::Yottaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yottaliter operator""_yottaliters(const long double value) noexcept {
		return xieite::units::Yottaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Ronnaliter operator""_ronnaliters(const unsigned long long int value) noexcept {
		return xieite::units::Ronnaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Ronnaliter operator""_ronnaliters(const long double value) noexcept {
		return xieite::units::Ronnaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quettaliter operator""_quettaliters(const unsigned long long int value) noexcept {
		return xieite::units::Quettaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quettaliter operator""_quettaliters(const long double value) noexcept {
		return xieite::units::Quettaliter(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::FluidOunce operator""_fluidOunces(const unsigned long long int value) noexcept {
		return xieite::units::FluidOunce(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::FluidOunce operator""_fluidOunces(const long double value) noexcept {
		return xieite::units::FluidOunce(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Gill operator""_gills(const unsigned long long int value) noexcept {
		return xieite::units::Gill(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Gill operator""_gills(const long double value) noexcept {
		return xieite::units::Gill(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Cup operator""_cups(const unsigned long long int value) noexcept {
		return xieite::units::Cup(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Cup operator""_cups(const long double value) noexcept {
		return xieite::units::Cup(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Pint operator""_pints(const unsigned long long int value) noexcept {
		return xieite::units::Pint(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Pint operator""_pints(const long double value) noexcept {
		return xieite::units::Pint(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quart operator""_quarts(const unsigned long long int value) noexcept {
		return xieite::units::Quart(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quart operator""_quarts(const long double value) noexcept {
		return xieite::units::Quart(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Gallon operator""_gallons(const unsigned long long int value) noexcept {
		return xieite::units::Gallon(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Gallon operator""_gallons(const long double value) noexcept {
		return xieite::units::Gallon(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Radian operator""_radians(const unsigned long long int value) noexcept {
		return xieite::units::Radian(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Radian operator""_radians(const long double value) noexcept {
		return xieite::units::Radian(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Degree operator""_degrees(const unsigned long long int value) noexcept {
		return xieite::units::Degree(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Degree operator""_degrees(const long double value) noexcept {
		return xieite::units::Degree(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Kelvin operator""_kelvin(const unsigned long long int value) noexcept {
		return xieite::units::Kelvin(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Kelvin operator""_kelvin(const long double value) noexcept {
		return xieite::units::Kelvin(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Celsius operator""_celsius(const unsigned long long int value) noexcept {
		return xieite::units::Celsius(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Celsius operator""_celsius(const long double value) noexcept {
		return xieite::units::Celsius(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Fahrenheit operator""_fahrenheit(const unsigned long long int value) noexcept {
		return xieite::units::Fahrenheit(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Fahrenheit operator""_fahrenheit(const long double value) noexcept {
		return xieite::units::Fahrenheit(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Rankine operator""_rankine(const unsigned long long int value) noexcept {
		return xieite::units::Rankine(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Rankine operator""_rankine(const long double value) noexcept {
		return xieite::units::Rankine(static_cast<double>(value));
	}
}
