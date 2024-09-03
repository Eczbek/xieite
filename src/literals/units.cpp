export module xieite:literals.units;

import :units.Angle;
import :units.Area;
import :units.convert;
import :units.Length;
import :units.Temperature;
import :units.Volume;

export namespace xieite::literals::units {
	[[nodiscard]] constexpr double operator""_quectometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Quectometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_quectometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Quectometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_rontometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Rontometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_rontometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Rontometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_yoctometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Yoctometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_yoctometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Yoctometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_zeptometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Zeptometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_zeptometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Zeptometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_attometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Attometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_attometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Attometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_femtometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Femtometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_femtometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Femtometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_picometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Picometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_picometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Picometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_nanometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Nanometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_nanometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Nanometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_micrometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Micrometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_micrometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Micrometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_millimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Millimetre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_millimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Millimetre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_centimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Centimetre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_centimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Centimetre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_decimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Decimetre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_decimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Decimetre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_metres(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr long double operator""_metres(const long double value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_decametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Decametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_decametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Decametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_hectometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Hectometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_hectometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Hectometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_kilometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Kilometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_kilometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Kilometre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_megametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Megametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_megametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Megametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_gigametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Gigametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_gigametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Gigametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_terametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Terametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_terametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Terametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_petametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Petametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_petametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Petametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_exametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Exametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_exametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Exametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_zettametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Zettametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_zettametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Zettametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_yottametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Yottametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_yottametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Yottametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_ronnametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Ronnametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_ronnametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Ronnametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_quettametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Quettametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_quettametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Quettametre, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_twips(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Twip, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_twips(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Twip, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_thous(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Thou, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_thous(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Thou, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_barleycorns(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Barleycorn, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_barleycorns(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Barleycorn, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_inches(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Inch, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_inches(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Inch, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_feet(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Foot, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_feet(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Foot, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_yards(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Yard, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_yards(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Yard, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_chains(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Chain, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_chains(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Chain, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_furlongs(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Furlong, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_furlongs(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Furlong, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_miles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Mile, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_miles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Mile, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_leagues(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::League, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_leagues(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::League, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_fathoms(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Fathom, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_fathoms(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Fathom, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_cables(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Cable, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_cables(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Cable, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_nauticalMiles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::NauticalMile, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_nauticalMiles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::NauticalMile, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_links(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Link, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_links(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Link, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_rods(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Rod, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_rods(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Rod, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_perches(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Perch, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_perches(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Perch, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_poles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Pole, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_poles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Pole, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_lugs(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Lug, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr long double operator""_lugs(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Length::Lug, xieite::units::Length::Metre);
	}

	[[nodiscard]] constexpr double operator""_squareQuectometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareQuectometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareQuectometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareQuectometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareRontometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareRontometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareRontometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareRontometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareYoctometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareYoctometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareYoctometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareYoctometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareZeptometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareZeptometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareZeptometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareZeptometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareAttometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareAttometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareAttometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareAttometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareFemtometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareFemtometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareFemtometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareFemtometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squarePicometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquarePicometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squarePicometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquarePicometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareNanometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareNanometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareNanometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareNanometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMicrometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareMicrometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareMicrometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareMicrometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMillimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareMillimetre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareMillimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareMillimetre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareCentimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareCentimetre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareCentimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareCentimetre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareDecimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareDecimetre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareDecimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareDecimetre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMetres(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr long double operator""_squareMetres(const long double value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_squareDecametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareDecametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareDecametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareDecametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareHectometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareHectometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareHectometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareHectometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareKilometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareKilometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareKilometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareKilometre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMegametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareMegametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareMegametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareMegametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareGigametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareGigametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareGigametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareGigametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareTerametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareTerametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareTerametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareTerametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squarePetametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquarePetametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squarePetametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquarePetametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareExametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareExametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareExametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareExametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareZettametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareZettametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareZettametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareZettametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareYottametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareYottametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareYottametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareYottametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareRonnametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareRonnametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareRonnametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareRonnametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareQuettametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareQuettametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareQuettametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareQuettametre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareInches(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareInch, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareInches(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareInch, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareFeet(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareFoot, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareFeet(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareFoot, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareYards(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareYard, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareYards(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareYard, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_squareMiles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareMile, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_squareMiles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareMile, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_roods(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareRood, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_roods(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::SquareRood, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_acres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Acre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_acres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Acre, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_decimilliares(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Decimilliare, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_decimilliares(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Decimilliare, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_centiare(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Centiare, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_centiare(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Centiare, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_deciares(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Deciare, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_deciares(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Deciare, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_ares(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Are, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_ares(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Are, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_decares(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Decare, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_decares(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Decare, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_hectares(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Hectare, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr long double operator""_hectares(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Area::Hectare, xieite::units::Area::SquareMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicQuectometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicQuectometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicQuectometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicQuectometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicRontometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicRontometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicRontometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicRontometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicYoctometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicYoctometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicYoctometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicYoctometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicZeptometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicZeptometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicZeptometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicZeptometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicAttometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicAttometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicAttometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicAttometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicFemtometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicFemtometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicFemtometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicFemtometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicPicometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicPicometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicPicometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicPicometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicNanometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicNanometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicNanometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicNanometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMicrometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicMicrometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicMicrometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicMicrometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMillimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicMillimetre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicMillimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicMillimetre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicCentimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicCentimetre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicCentimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicCentimetre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicDecimetres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicDecimetre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicDecimetres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicDecimetre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMetres(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr long double operator""_cubicMetres(const long double value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_cubicDecametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicDecametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicDecametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicDecametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicHectometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicHectometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicHectometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicHectometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicKilometres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicKilometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicKilometres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicKilometre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMegametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicMegametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicMegametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicMegametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicGigametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicGigametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicGigametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicGigametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicTerametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicTerametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicTerametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicTerametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicPetametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicPetametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicPetametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicPetametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicExametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicExametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicExametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicExametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicZettametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicZettametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicZettametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicZettametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicYottametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicYottametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicYottametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicYottametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicRonnametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicRonnametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicRonnametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicRonnametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicQuettametres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicQuettametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicQuettametres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicQuettametre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicInches(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicInch, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicInches(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicInch, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicFeet(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicFoot, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicFeet(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicFoot, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicYards(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicYard, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicYards(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicYard, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cubicMiles(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicMile, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cubicMiles(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::CubicMile, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_quectolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Quectolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_quectolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Quectolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_rontolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Rontolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_rontolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Rontolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_yoctolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Yoctolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_yoctolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Yoctolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_zeptolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Zeptolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_zeptolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Zeptolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_attolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Attolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_attolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Attolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_femtolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Femtolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_femtolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Femtolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_picolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Picolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_picolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Picolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_nanolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Nanolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_nanolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Nanolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_microlitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Microlitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_microlitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Microlitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_millilitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Millilitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_millilitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Millilitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_centilitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Centilitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_centilitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Centilitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_decilitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Decilitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_decilitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Decilitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_litres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Litre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_litres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Litre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_decalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Decalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_decalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Decalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_hectolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Hectolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_hectolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Hectolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_kilolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Kilolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_kilolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Kilolitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_megalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Megalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_megalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Megalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_gigalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Gigalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_gigalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Gigalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_teralitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Teralitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_teralitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Teralitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_petalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Petalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_petalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Petalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_exalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Exalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_exalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Exalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_zettalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Zettalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_zettalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Zettalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_yottalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Yottalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_yottalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Yottalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_ronnalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Ronnalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_ronnalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Ronnalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_quettalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Quettalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_quettalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Quettalitre, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_fluidOunces(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::FluidOunce, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_fluidOunces(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::FluidOunce, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_gills(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Gill, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_gills(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Gill, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_cups(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Cup, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_cups(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Cup, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_pints(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Pint, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_pints(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Pint, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_quarts(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Quart, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_quarts(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Quart, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_gallons(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Gallon, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr long double operator""_gallons(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::Gallon, xieite::units::Volume::CubicMetre);
	}

	[[nodiscard]] constexpr double operator""_radians(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr long double operator""_radians(const long double value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_degrees(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Angle::Degree, xieite::units::Angle::Radian);
	}

	[[nodiscard]] constexpr long double operator""_degrees(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Angle::Degree, xieite::units::Angle::Radian);
	}

	[[nodiscard]] constexpr double operator""_kelvin(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr long double operator""_kelvin(const long double value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_celsius(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Temperature::Celsius, xieite::units::Temperature::Kelvin);
	}

	[[nodiscard]] constexpr long double operator""_celsius(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Temperature::Celsius, xieite::units::Temperature::Kelvin);
	}

	[[nodiscard]] constexpr double operator""_fahrenheit(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Temperature::Fahrenheit, xieite::units::Temperature::Kelvin);
	}

	[[nodiscard]] constexpr long double operator""_fahrenheit(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Temperature::Fahrenheit, xieite::units::Temperature::Kelvin);
	}

	[[nodiscard]] constexpr double operator""_rankine(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Temperature::Rankine, xieite::units::Temperature::Kelvin);
	}

	[[nodiscard]] constexpr long double operator""_rankine(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Temperature::Rankine, xieite::units::Temperature::Kelvin);
	}
}
