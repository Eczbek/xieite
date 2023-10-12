#ifndef XIEITE_HEADER_UNITS_LITERALS_AREAS
#	define XIEITE_HEADER_UNITS_LITERALS_AREAS

#	include "../../units/areas.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_squareNanometers(const long double value) noexcept {
		return value * xieite::units::SquareNanometer::num / xieite::units::SquareNanometer::den;
	}

	[[nodiscard]] constexpr double operator""_squareNanometers(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareNanometer::num / xieite::units::SquareNanometer::den;
	}

	[[nodiscard]] constexpr double operator""_squareMicrometers(const long double value) noexcept {
		return value * xieite::units::SquareMicrometer::num / xieite::units::SquareMicrometer::den;
	}

	[[nodiscard]] constexpr double operator""_squareMicrometers(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareMicrometer::num / xieite::units::SquareMicrometer::den;
	}

	[[nodiscard]] constexpr double operator""_squareMillimeters(const long double value) noexcept {
		return value * xieite::units::SquareMillimeter::num / xieite::units::SquareMillimeter::den;
	}

	[[nodiscard]] constexpr double operator""_squareMillimeters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareMillimeter::num / xieite::units::SquareMillimeter::den;
	}

	[[nodiscard]] constexpr double operator""_squareCentimeters(const long double value) noexcept {
		return value * xieite::units::SquareCentimeter::num / xieite::units::SquareCentimeter::den;
	}

	[[nodiscard]] constexpr double operator""_squareCentimeters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareCentimeter::num / xieite::units::SquareCentimeter::den;
	}

	[[nodiscard]] constexpr double operator""_squareDecimeters(const long double value) noexcept {
		return value * xieite::units::SquareDecimeter::num / xieite::units::SquareDecimeter::den;
	}

	[[nodiscard]] constexpr double operator""_squareDecimeters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareDecimeter::num / xieite::units::SquareDecimeter::den;
	}

	[[nodiscard]] constexpr double operator""_squareMeters(const long double value) noexcept {
		return value * xieite::units::SquareMeter::num / xieite::units::SquareMeter::den;
	}

	[[nodiscard]] constexpr double operator""_squareMeters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareMeter::num / xieite::units::SquareMeter::den;
	}

	[[nodiscard]] constexpr double operator""_squareDecameters(const long double value) noexcept {
		return value * xieite::units::SquareDecameter::num / xieite::units::SquareDecameter::den;
	}

	[[nodiscard]] constexpr double operator""_squareDecameters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareDecameter::num / xieite::units::SquareDecameter::den;
	}

	[[nodiscard]] constexpr double operator""_squareHectometers(const long double value) noexcept {
		return value * xieite::units::SquareHectometer::num / xieite::units::SquareHectometer::den;
	}

	[[nodiscard]] constexpr double operator""_squareHectometers(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareHectometer::num / xieite::units::SquareHectometer::den;
	}

	[[nodiscard]] constexpr double operator""_squareKilometers(const long double value) noexcept {
		return value * xieite::units::SquareKilometer::num / xieite::units::SquareKilometer::den;
	}

	[[nodiscard]] constexpr double operator""_squareKilometers(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareKilometer::num / xieite::units::SquareKilometer::den;
	}

	[[nodiscard]] constexpr double operator""_squareMegameters(const long double value) noexcept {
		return value * xieite::units::SquareMegameter::num / xieite::units::SquareMegameter::den;
	}

	[[nodiscard]] constexpr double operator""_squareMegameters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareMegameter::num / xieite::units::SquareMegameter::den;
	}

	[[nodiscard]] constexpr double operator""_squareGigameters(const long double value) noexcept {
		return value * xieite::units::SquareGigameter::num / xieite::units::SquareGigameter::den;
	}

	[[nodiscard]] constexpr double operator""_squareGigameters(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareGigameter::num / xieite::units::SquareGigameter::den;
	}

	[[nodiscard]] constexpr double operator""_squareThous(const long double value) noexcept {
		return value * xieite::units::SquareThou::num / xieite::units::SquareThou::den;
	}

	[[nodiscard]] constexpr double operator""_squareThous(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareThou::num / xieite::units::SquareThou::den;
	}

	[[nodiscard]] constexpr double operator""_squareBarleycorns(const long double value) noexcept {
		return value * xieite::units::SquareBarleycorn::num / xieite::units::SquareBarleycorn::den;
	}

	[[nodiscard]] constexpr double operator""_squareBarleycorns(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareBarleycorn::num / xieite::units::SquareBarleycorn::den;
	}

	[[nodiscard]] constexpr double operator""_squareInches(const long double value) noexcept {
		return value * xieite::units::SquareInch::num / xieite::units::SquareInch::den;
	}

	[[nodiscard]] constexpr double operator""_squareInches(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareInch::num / xieite::units::SquareInch::den;
	}

	[[nodiscard]] constexpr double operator""_squareFeet(const long double value) noexcept {
		return value * xieite::units::SquareFoot::num / xieite::units::SquareFoot::den;
	}

	[[nodiscard]] constexpr double operator""_squareFeet(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareFoot::num / xieite::units::SquareFoot::den;
	}

	[[nodiscard]] constexpr double operator""_squareYards(const long double value) noexcept {
		return value * xieite::units::SquareYard::num / xieite::units::SquareYard::den;
	}

	[[nodiscard]] constexpr double operator""_squareYards(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareYard::num / xieite::units::SquareYard::den;
	}

	[[nodiscard]] constexpr double operator""_squareChains(const long double value) noexcept {
		return value * xieite::units::SquareChain::num / xieite::units::SquareChain::den;
	}

	[[nodiscard]] constexpr double operator""_squareChains(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareChain::num / xieite::units::SquareChain::den;
	}

	[[nodiscard]] constexpr double operator""_squareFurlongs(const long double value) noexcept {
		return value * xieite::units::SquareFurlong::num / xieite::units::SquareFurlong::den;
	}

	[[nodiscard]] constexpr double operator""_squareFurlongs(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareFurlong::num / xieite::units::SquareFurlong::den;
	}

	[[nodiscard]] constexpr double operator""_squareMiles(const long double value) noexcept {
		return value * xieite::units::SquareMile::num / xieite::units::SquareMile::den;
	}

	[[nodiscard]] constexpr double operator""_squareMiles(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareMile::num / xieite::units::SquareMile::den;
	}

	[[nodiscard]] constexpr double operator""_squareLeagues(const long double value) noexcept {
		return value * xieite::units::SquareLeague::num / xieite::units::SquareLeague::den;
	}

	[[nodiscard]] constexpr double operator""_squareLeagues(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareLeague::num / xieite::units::SquareLeague::den;
	}

	[[nodiscard]] constexpr double operator""_squareFathoms(const long double value) noexcept {
		return value * xieite::units::SquareFathom::num / xieite::units::SquareFathom::den;
	}

	[[nodiscard]] constexpr double operator""_squareFathoms(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareFathom::num / xieite::units::SquareFathom::den;
	}

	[[nodiscard]] constexpr double operator""_squareCables(const long double value) noexcept {
		return value * xieite::units::SquareCable::num / xieite::units::SquareCable::den;
	}

	[[nodiscard]] constexpr double operator""_squareCables(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareCable::num / xieite::units::SquareCable::den;
	}

	[[nodiscard]] constexpr double operator""_squareNauticalMiles(const long double value) noexcept {
		return value * xieite::units::SquareNauticalMile::num / xieite::units::SquareNauticalMile::den;
	}

	[[nodiscard]] constexpr double operator""_squareNauticalMiles(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareNauticalMile::num / xieite::units::SquareNauticalMile::den;
	}

	[[nodiscard]] constexpr double operator""_squareLinks(const long double value) noexcept {
		return value * xieite::units::SquareLink::num / xieite::units::SquareLink::den;
	}

	[[nodiscard]] constexpr double operator""_squareLinks(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareLink::num / xieite::units::SquareLink::den;
	}

	[[nodiscard]] constexpr double operator""_squareRods(const long double value) noexcept {
		return value * xieite::units::SquareRod::num / xieite::units::SquareRod::den;
	}

	[[nodiscard]] constexpr double operator""_squareRods(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::SquareRod::num / xieite::units::SquareRod::den;
	}

	[[nodiscard]] constexpr double operator""_perches(const long double value) noexcept {
		return value * xieite::units::Perch::num / xieite::units::Perch::den;
	}

	[[nodiscard]] constexpr double operator""_perches(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Perch::num / xieite::units::Perch::den;
	}

	[[nodiscard]] constexpr double operator""_roods(const long double value) noexcept {
		return value * xieite::units::Rood::num / xieite::units::Rood::den;
	}

	[[nodiscard]] constexpr double operator""_roods(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Rood::num / xieite::units::Rood::den;
	}

	[[nodiscard]] constexpr double operator""_acres(const long double value) noexcept {
		return value * xieite::units::Acre::num / xieite::units::Acre::den;
	}

	[[nodiscard]] constexpr double operator""_acres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Acre::num / xieite::units::Acre::den;
	}
}

#endif
