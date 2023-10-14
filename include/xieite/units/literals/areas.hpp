#ifndef XIEITE_HEADER_UNITS_LITERALS_AREAS
#	define XIEITE_HEADER_UNITS_LITERALS_AREAS

#	include "../../units/areas.hpp"
#	include "../../units/convert.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_squareNanometers(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareNanometer, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareNanometers(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareNanometer, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareMicrometers(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareMicrometer, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareMicrometers(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareMicrometer, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareMillimeters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareMillimeter, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareMillimeters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareMillimeter, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareCentimeters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareCentimeter, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareCentimeters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareCentimeter, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareDecimeters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareDecimeter, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareDecimeters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareDecimeter, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareMeters(const long double value) noexcept {
		return value;
	}

	[[nodiscard]] constexpr double operator""_squareMeters(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_squareDecameters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareDecameter, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareDecameters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareDecameter, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareHectometers(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareHectometer, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareHectometers(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareHectometer, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareKilometers(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareKilometer, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareKilometers(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareKilometer, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareMegameters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareMegameter, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareMegameters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareMegameter, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareGigameters(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareGigameter, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareGigameters(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareGigameter, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareThous(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareThou, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareThous(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareThou, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareBarleycorns(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareBarleycorn, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareBarleycorns(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareBarleycorn, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareInches(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareInch, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareInches(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareInch, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareFeet(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareFoot, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareFeet(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareFoot, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareYards(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareYard, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareYards(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareYard, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareChains(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareChain, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareChains(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareChain, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareFurlongs(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareFurlong, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareFurlongs(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareFurlong, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareMiles(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareMile, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareMiles(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareMile, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareLeagues(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareLeague, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareLeagues(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareLeague, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareFathoms(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareFathom, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareFathoms(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareFathom, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareCables(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareCable, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareCables(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareCable, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareNauticalMiles(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareNauticalMile, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareNauticalMiles(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareNauticalMile, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareLinks(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareLink, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareLinks(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareLink, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareRods(const long double value) noexcept {
		return xieite::units::convert<xieite::units::SquareRod, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_squareRods(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::SquareRod, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_perches(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Perch, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_perches(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Perch, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_roods(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Rood, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_roods(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Rood, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_acres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Acre, xieite::units::SquareMeter>(value);
	}

	[[nodiscard]] constexpr double operator""_acres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Acre, xieite::units::SquareMeter>(value);
	}
}

#endif
