#ifndef XIEITE_HEADER_LITERALS_UNITS
#	define XIEITE_HEADER_LITERALS_UNITS

#	include "../units/angles.hpp"
#	include "../units/areas.hpp"
#	include "../units/convert.hpp"
#	include "../units/lengths.hpp"
#	include "../units/temperatures.hpp"
#	include "../units/volumes.hpp"

namespace xieite::literals::units {
	[[nodiscard]] constexpr double operator""_quectometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::quectometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_quectometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::quectometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_rontometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::rontometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_rontometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::rontometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_yoctometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::yoctometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_yoctometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::yoctometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_zeptometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::zeptometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_zeptometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::zeptometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_attometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::attometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_attometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::attometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_femtometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::femtometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_femtometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::femtometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_picometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::picometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_picometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::picometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_nanometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::nanometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_nanometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::nanometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_micrometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::micrometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_micrometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::micrometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_millimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::millimetre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_millimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::millimetre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_centimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::centimetre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_centimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::centimetre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_decimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::decimetre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_decimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::decimetre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_metres(const long double value) noexcept {
		return value;
	}

	[[nodiscard]] constexpr double operator""_metres(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_decametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::decametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_decametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::decametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_hectometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::hectometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_hectometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::hectometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_kilometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::kilometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_kilometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::kilometre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_megametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::megametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_megametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::megametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_gigametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::gigametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_gigametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::gigametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_terametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::terametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_terametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::terametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_petametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::petametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_petametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::petametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_exametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::exametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_exametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::exametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_zettametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::zettametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_zettametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::zettametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_yottametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::yottametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_yottametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::yottametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_ronnametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::ronnametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_ronnametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::ronnametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_quettametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::quettametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_quettametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::quettametre, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_twips(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::twip, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_twips(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::twip, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_thous(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::thou, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_thous(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::thou, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_barleycorns(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::barleycorn, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_barleycorns(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::barleycorn, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_inches(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::inch, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_inches(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::inch, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_feet(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::foot, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_feet(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::foot, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_yards(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::yard, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_yards(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::yard, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_chains(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::chain, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_chains(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::chain, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_furlongs(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::furlong, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_furlongs(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::furlong, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_miles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::mile, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_miles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::mile, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_leagues(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::league, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_leagues(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::league, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_fathoms(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::fathom, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_fathoms(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::fathom, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_cables(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::cable, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_cables(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::cable, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_nauticalMiles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::nauticalMile, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_nauticalMiles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::nauticalMile, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_links(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::link, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_links(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::link, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_rods(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::rod, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_rods(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::rod, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_perches(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::perch, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_perches(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::perch, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_poles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::pole, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_poles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::pole, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_lugs(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::lug, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_lugs(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::lug, xieite::units::Length::metre);
	}

	[[nodiscard]] constexpr double operator""_squareQuectometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareQuectometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareQuectometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareQuectometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareRontometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareRontometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareRontometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareRontometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareYoctometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareYoctometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareYoctometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareYoctometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareZeptometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareZeptometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareZeptometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareZeptometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareAttometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareAttometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareAttometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareAttometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareFemtometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareFemtometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareFemtometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareFemtometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squarePicometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squarePicometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squarePicometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squarePicometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareNanometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareNanometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareNanometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareNanometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMicrometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareMicrometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMicrometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareMicrometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMillimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareMillimetre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMillimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareMillimetre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareCentimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareCentimetre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareCentimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareCentimetre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareDecimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareDecimetre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareDecimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareDecimetre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMetres(const long double value) noexcept {
		return value;
	}

	[[nodiscard]] constexpr double operator""_squareMetres(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_squareDecametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareDecametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareDecametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareDecametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareHectometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareHectometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareHectometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareHectometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareKilometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareKilometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareKilometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareKilometre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMegametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareMegametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMegametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareMegametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareGigametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareGigametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareGigametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareGigametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareTerametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareTerametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareTerametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareTerametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squarePetametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squarePetametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squarePetametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squarePetametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareExametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareExametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareExametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareExametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareZettametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareZettametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareZettametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareZettametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareYottametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareYottametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareYottametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareYottametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareRonnametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareRonnametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareRonnametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareRonnametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareQuettametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareQuettametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareQuettametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareQuettametre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareInches(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareInch, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareInches(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareInch, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareFeet(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareFoot, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareFeet(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareFoot, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareYards(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareYard, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareYards(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareYard, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMiles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareMile, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMiles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareMile, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_roods(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareRood, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_roods(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareRood, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_acres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareAcre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_acres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareAcre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_decimilliares(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareDecimilliare, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_decimilliares(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareDecimilliare, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_centiare(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareCentiare, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_centiare(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareCentiare, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_deciares(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareDeciare, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_deciares(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareDeciare, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_ares(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareAre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_ares(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareAre, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_decares(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareDecare, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_decares(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareDecare, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_hectares(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareHectare, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_hectares(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::squareHectare, xieite::units::Area::squareMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicQuectometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicQuectometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicQuectometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicQuectometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicRontometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicRontometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicRontometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicRontometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicYoctometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicYoctometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicYoctometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicYoctometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicZeptometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicZeptometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicZeptometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicZeptometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicAttometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicAttometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicAttometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicAttometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicFemtometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicFemtometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicFemtometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicFemtometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicPicometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicPicometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicPicometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicPicometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicNanometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicNanometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicNanometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicNanometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMicrometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicMicrometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMicrometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicMicrometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMillimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicMillimetre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMillimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicMillimetre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicCentimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicCentimetre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicCentimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicCentimetre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicDecimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicDecimetre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicDecimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicDecimetre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMetres(const long double value) noexcept {
		return value;
	}

	[[nodiscard]] constexpr double operator""_cubicMetres(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_cubicDecametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicDecametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicDecametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicDecametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicHectometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicHectometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicHectometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicHectometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicKilometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicKilometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicKilometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicKilometre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMegametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicMegametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMegametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicMegametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicGigametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicGigametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicGigametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicGigametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicTerametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicTerametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicTerametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicTerametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicPetametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicPetametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicPetametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicPetametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicExametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicExametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicExametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicExametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicZettametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicZettametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicZettametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicZettametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicYottametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicYottametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicYottametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicYottametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicRonnametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicRonnametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicRonnametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicRonnametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicQuettametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicQuettametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicQuettametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicQuettametre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicInches(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicInch, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicInches(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicInch, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicFeet(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicFoot, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicFeet(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicFoot, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicYards(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicYard, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicYards(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicYard, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMiles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicMile, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMiles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cubicMile, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_quectolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::quectolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_quectolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::quectolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_rontolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::rontolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_rontolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::rontolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_yoctolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::yoctolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_yoctolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::yoctolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_zeptolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::zeptolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_zeptolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::zeptolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_attolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::attolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_attolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::attolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_femtolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::femtolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_femtolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::femtolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_picolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::picolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_picolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::picolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_nanolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::nanolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_nanolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::nanolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_microlitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::microlitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_microlitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::microlitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_millilitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::millilitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_millilitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::millilitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_centilitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::centilitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_centilitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::centilitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_decilitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::decilitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_decilitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::decilitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_litres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::litre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_litres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::litre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_decalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::decalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_decalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::decalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_hectolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::hectolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_hectolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::hectolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_kilolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::kilolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_kilolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::kilolitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_megalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::megalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_megalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::megalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_gigalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::gigalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_gigalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::gigalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_teralitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::teralitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_teralitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::teralitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_petalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::petalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_petalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::petalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_exalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::exalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_exalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::exalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_zettalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::zettalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_zettalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::zettalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_yottalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::yottalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_yottalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::yottalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_ronnalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::ronnalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_ronnalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::ronnalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_quettalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::quettalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_quettalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::quettalitre, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_fluidOunces(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::fluidOunce, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_fluidOunces(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::fluidOunce, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_gills(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::gill, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_gills(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::gill, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cups(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cup, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cups(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cup, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_pints(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::pint, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_pints(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::pint, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_quarts(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::quart, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_quarts(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::quart, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_gallons(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::gallon, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_gallons(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::gallon, xieite::units::Volume::cubicMetre);
	}

	[[nodiscard]] constexpr double operator""_radians(const long double value) noexcept {
		return value;
	}

	[[nodiscard]] constexpr double operator""_radians(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_degrees(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Angle::degree, xieite::units::Angle::radian);
	}

	[[nodiscard]] constexpr double operator""_degrees(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Angle::degree, xieite::units::Angle::radian);
	}

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
