#ifndef XIEITE_HEADER_UNITS_LITERALS_LENGTHS
#	define XIEITE_HEADER_UNITS_LITERALS_LENGTHS

#	include "../../units/convert.hpp"
#	include "../../units/length.hpp"

namespace xieite::units::literals {
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
}

#endif
