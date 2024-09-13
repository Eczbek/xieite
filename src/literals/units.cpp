export module xieite:literals.units;

import :units.angle;
import :units.area;
import :units.length;
import :units.temperature;
import :units.volume;

export namespace xieite::literals::units {
	[[nodiscard]] constexpr xieite::units::Quectometre operator""_quectometres(const unsigned long long int value) noexcept {
		return xieite::units::Quectometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quectometre operator""_quectometres(const long double value) noexcept {
		return xieite::units::Quectometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Rontometre operator""_rontometres(const unsigned long long int value) noexcept {
		return xieite::units::Rontometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Rontometre operator""_rontometres(const long double value) noexcept {
		return xieite::units::Rontometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yoctometre operator""_yoctometres(const unsigned long long int value) noexcept {
		return xieite::units::Yoctometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yoctometre operator""_yoctometres(const long double value) noexcept {
		return xieite::units::Yoctometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zeptometre operator""_zeptometres(const unsigned long long int value) noexcept {
		return xieite::units::Zeptometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zeptometre operator""_zeptometres(const long double value) noexcept {
		return xieite::units::Zeptometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Attometre operator""_attometres(const unsigned long long int value) noexcept {
		return xieite::units::Attometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Attometre operator""_attometres(const long double value) noexcept {
		return xieite::units::Attometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Femtometre operator""_femtometres(const unsigned long long int value) noexcept {
		return xieite::units::Femtometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Femtometre operator""_femtometres(const long double value) noexcept {
		return xieite::units::Femtometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Picometre operator""_picometres(const unsigned long long int value) noexcept {
		return xieite::units::Picometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Picometre operator""_picometres(const long double value) noexcept {
		return xieite::units::Picometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Nanometre operator""_nanometres(const unsigned long long int value) noexcept {
		return xieite::units::Nanometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Nanometre operator""_nanometres(const long double value) noexcept {
		return xieite::units::Nanometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Micrometre operator""_micrometres(const unsigned long long int value) noexcept {
		return xieite::units::Micrometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Micrometre operator""_micrometres(const long double value) noexcept {
		return xieite::units::Micrometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Millimetre operator""_millimetres(const unsigned long long int value) noexcept {
		return xieite::units::Millimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Millimetre operator""_millimetres(const long double value) noexcept {
		return xieite::units::Millimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Centimetre operator""_centimetres(const unsigned long long int value) noexcept {
		return xieite::units::Centimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Centimetre operator""_centimetres(const long double value) noexcept {
		return xieite::units::Centimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decimetre operator""_decimetres(const unsigned long long int value) noexcept {
		return xieite::units::Decimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decimetre operator""_decimetres(const long double value) noexcept {
		return xieite::units::Decimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Metre operator""_metres(const unsigned long long int value) noexcept {
		return xieite::units::Metre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Metre operator""_metres(const long double value) noexcept {
		return xieite::units::Metre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decametre operator""_decametres(const unsigned long long int value) noexcept {
		return xieite::units::Decametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decametre operator""_decametres(const long double value) noexcept {
		return xieite::units::Decametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Hectometre operator""_hectometres(const unsigned long long int value) noexcept {
		return xieite::units::Hectometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Hectometre operator""_hectometres(const long double value) noexcept {
		return xieite::units::Hectometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Kilometre operator""_kilometres(const unsigned long long int value) noexcept {
		return xieite::units::Kilometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Kilometre operator""_kilometres(const long double value) noexcept {
		return xieite::units::Kilometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Megametre operator""_megametres(const unsigned long long int value) noexcept {
		return xieite::units::Megametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Megametre operator""_megametres(const long double value) noexcept {
		return xieite::units::Megametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Gigametre operator""_gigametres(const unsigned long long int value) noexcept {
		return xieite::units::Gigametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Gigametre operator""_gigametres(const long double value) noexcept {
		return xieite::units::Gigametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Terametre operator""_terametres(const unsigned long long int value) noexcept {
		return xieite::units::Terametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Terametre operator""_terametres(const long double value) noexcept {
		return xieite::units::Terametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Petametre operator""_petametres(const unsigned long long int value) noexcept {
		return xieite::units::Petametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Petametre operator""_petametres(const long double value) noexcept {
		return xieite::units::Petametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Exametre operator""_exametres(const unsigned long long int value) noexcept {
		return xieite::units::Exametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Exametre operator""_exametres(const long double value) noexcept {
		return xieite::units::Exametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zettametre operator""_zettametres(const unsigned long long int value) noexcept {
		return xieite::units::Zettametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zettametre operator""_zettametres(const long double value) noexcept {
		return xieite::units::Zettametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yottametre operator""_yottametres(const unsigned long long int value) noexcept {
		return xieite::units::Yottametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yottametre operator""_yottametres(const long double value) noexcept {
		return xieite::units::Yottametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Ronnametre operator""_ronnametres(const unsigned long long int value) noexcept {
		return xieite::units::Ronnametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Ronnametre operator""_ronnametres(const long double value) noexcept {
		return xieite::units::Ronnametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quettametre operator""_quettametres(const unsigned long long int value) noexcept {
		return xieite::units::Quettametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quettametre operator""_quettametres(const long double value) noexcept {
		return xieite::units::Quettametre(static_cast<double>(value));
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

	[[nodiscard]] constexpr xieite::units::SquareQuectometre operator""_squareQuectometres(const unsigned long long int value) noexcept {
		return xieite::units::SquareQuectometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareQuectometre operator""_squareQuectometres(const long double value) noexcept {
		return xieite::units::SquareQuectometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareRontometre operator""_squareRontometres(const unsigned long long int value) noexcept {
		return xieite::units::SquareRontometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareRontometre operator""_squareRontometres(const long double value) noexcept {
		return xieite::units::SquareRontometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareYoctometre operator""_squareYoctometres(const unsigned long long int value) noexcept {
		return xieite::units::SquareYoctometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareYoctometre operator""_squareYoctometres(const long double value) noexcept {
		return xieite::units::SquareYoctometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareZeptometre operator""_squareZeptometres(const unsigned long long int value) noexcept {
		return xieite::units::SquareZeptometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareZeptometre operator""_squareZeptometres(const long double value) noexcept {
		return xieite::units::SquareZeptometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareAttometre operator""_squareAttometres(const unsigned long long int value) noexcept {
		return xieite::units::SquareAttometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareAttometre operator""_squareAttometres(const long double value) noexcept {
		return xieite::units::SquareAttometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareFemtometre operator""_squareFemtometres(const unsigned long long int value) noexcept {
		return xieite::units::SquareFemtometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareFemtometre operator""_squareFemtometres(const long double value) noexcept {
		return xieite::units::SquareFemtometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquarePicometre operator""_squarePicometres(const unsigned long long int value) noexcept {
		return xieite::units::SquarePicometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquarePicometre operator""_squarePicometres(const long double value) noexcept {
		return xieite::units::SquarePicometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareNanometre operator""_squareNanometres(const unsigned long long int value) noexcept {
		return xieite::units::SquareNanometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareNanometre operator""_squareNanometres(const long double value) noexcept {
		return xieite::units::SquareNanometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMicrometre operator""_squareMicrometres(const unsigned long long int value) noexcept {
		return xieite::units::SquareMicrometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMicrometre operator""_squareMicrometres(const long double value) noexcept {
		return xieite::units::SquareMicrometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMillimetre operator""_squareMillimetres(const unsigned long long int value) noexcept {
		return xieite::units::SquareMillimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMillimetre operator""_squareMillimetres(const long double value) noexcept {
		return xieite::units::SquareMillimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareCentimetre operator""_squareCentimetres(const unsigned long long int value) noexcept {
		return xieite::units::SquareCentimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareCentimetre operator""_squareCentimetres(const long double value) noexcept {
		return xieite::units::SquareCentimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareDecimetre operator""_squareDecimetres(const unsigned long long int value) noexcept {
		return xieite::units::SquareDecimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareDecimetre operator""_squareDecimetres(const long double value) noexcept {
		return xieite::units::SquareDecimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMetre operator""_squareMetres(const unsigned long long int value) noexcept {
		return xieite::units::SquareMetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMetre operator""_squareMetres(const long double value) noexcept {
		return xieite::units::SquareMetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareDecametre operator""_squareDecametres(const unsigned long long int value) noexcept {
		return xieite::units::SquareDecametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareDecametre operator""_squareDecametres(const long double value) noexcept {
		return xieite::units::SquareDecametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareHectometre operator""_squareHectometres(const unsigned long long int value) noexcept {
		return xieite::units::SquareHectometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareHectometre operator""_squareHectometres(const long double value) noexcept {
		return xieite::units::SquareHectometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareKilometre operator""_squareKilometres(const unsigned long long int value) noexcept {
		return xieite::units::SquareKilometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareKilometre operator""_squareKilometres(const long double value) noexcept {
		return xieite::units::SquareKilometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMegametre operator""_squareMegametres(const unsigned long long int value) noexcept {
		return xieite::units::SquareMegametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareMegametre operator""_squareMegametres(const long double value) noexcept {
		return xieite::units::SquareMegametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareGigametre operator""_squareGigametres(const unsigned long long int value) noexcept {
		return xieite::units::SquareGigametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareGigametre operator""_squareGigametres(const long double value) noexcept {
		return xieite::units::SquareGigametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareTerametre operator""_squareTerametres(const unsigned long long int value) noexcept {
		return xieite::units::SquareTerametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareTerametre operator""_squareTerametres(const long double value) noexcept {
		return xieite::units::SquareTerametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquarePetametre operator""_squarePetametres(const unsigned long long int value) noexcept {
		return xieite::units::SquarePetametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquarePetametre operator""_squarePetametres(const long double value) noexcept {
		return xieite::units::SquarePetametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareExametre operator""_squareExametres(const unsigned long long int value) noexcept {
		return xieite::units::SquareExametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareExametre operator""_squareExametres(const long double value) noexcept {
		return xieite::units::SquareExametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareZettametre operator""_squareZettametres(const unsigned long long int value) noexcept {
		return xieite::units::SquareZettametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareZettametre operator""_squareZettametres(const long double value) noexcept {
		return xieite::units::SquareZettametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareYottametre operator""_squareYottametres(const unsigned long long int value) noexcept {
		return xieite::units::SquareYottametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareYottametre operator""_squareYottametres(const long double value) noexcept {
		return xieite::units::SquareYottametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareRonnametre operator""_squareRonnametres(const unsigned long long int value) noexcept {
		return xieite::units::SquareRonnametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareRonnametre operator""_squareRonnametres(const long double value) noexcept {
		return xieite::units::SquareRonnametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareQuettametre operator""_squareQuettametres(const unsigned long long int value) noexcept {
		return xieite::units::SquareQuettametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::SquareQuettametre operator""_squareQuettametres(const long double value) noexcept {
		return xieite::units::SquareQuettametre(static_cast<double>(value));
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

	[[nodiscard]] constexpr xieite::units::CubicQuectometre operator""_cubicQuectometres(const unsigned long long int value) noexcept {
		return xieite::units::CubicQuectometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicQuectometre operator""_cubicQuectometres(const long double value) noexcept {
		return xieite::units::CubicQuectometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicRontometre operator""_cubicRontometres(const unsigned long long int value) noexcept {
		return xieite::units::CubicRontometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicRontometre operator""_cubicRontometres(const long double value) noexcept {
		return xieite::units::CubicRontometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicYoctometre operator""_cubicYoctometres(const unsigned long long int value) noexcept {
		return xieite::units::CubicYoctometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicYoctometre operator""_cubicYoctometres(const long double value) noexcept {
		return xieite::units::CubicYoctometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicZeptometre operator""_cubicZeptometres(const unsigned long long int value) noexcept {
		return xieite::units::CubicZeptometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicZeptometre operator""_cubicZeptometres(const long double value) noexcept {
		return xieite::units::CubicZeptometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicAttometre operator""_cubicAttometres(const unsigned long long int value) noexcept {
		return xieite::units::CubicAttometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicAttometre operator""_cubicAttometres(const long double value) noexcept {
		return xieite::units::CubicAttometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicFemtometre operator""_cubicFemtometres(const unsigned long long int value) noexcept {
		return xieite::units::CubicFemtometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicFemtometre operator""_cubicFemtometres(const long double value) noexcept {
		return xieite::units::CubicFemtometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicPicometre operator""_cubicPicometres(const unsigned long long int value) noexcept {
		return xieite::units::CubicPicometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicPicometre operator""_cubicPicometres(const long double value) noexcept {
		return xieite::units::CubicPicometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicNanometre operator""_cubicNanometres(const unsigned long long int value) noexcept {
		return xieite::units::CubicNanometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicNanometre operator""_cubicNanometres(const long double value) noexcept {
		return xieite::units::CubicNanometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMicrometre operator""_cubicMicrometres(const unsigned long long int value) noexcept {
		return xieite::units::CubicMicrometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMicrometre operator""_cubicMicrometres(const long double value) noexcept {
		return xieite::units::CubicMicrometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMillimetre operator""_cubicMillimetres(const unsigned long long int value) noexcept {
		return xieite::units::CubicMillimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMillimetre operator""_cubicMillimetres(const long double value) noexcept {
		return xieite::units::CubicMillimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicCentimetre operator""_cubicCentimetres(const unsigned long long int value) noexcept {
		return xieite::units::CubicCentimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicCentimetre operator""_cubicCentimetres(const long double value) noexcept {
		return xieite::units::CubicCentimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicDecimetre operator""_cubicDecimetres(const unsigned long long int value) noexcept {
		return xieite::units::CubicDecimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicDecimetre operator""_cubicDecimetres(const long double value) noexcept {
		return xieite::units::CubicDecimetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMetre operator""_cubicMetres(const unsigned long long int value) noexcept {
		return xieite::units::CubicMetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMetre operator""_cubicMetres(const long double value) noexcept {
		return xieite::units::CubicMetre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicDecametre operator""_cubicDecametres(const unsigned long long int value) noexcept {
		return xieite::units::CubicDecametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicDecametre operator""_cubicDecametres(const long double value) noexcept {
		return xieite::units::CubicDecametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicHectometre operator""_cubicHectometres(const unsigned long long int value) noexcept {
		return xieite::units::CubicHectometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicHectometre operator""_cubicHectometres(const long double value) noexcept {
		return xieite::units::CubicHectometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicKilometre operator""_cubicKilometres(const unsigned long long int value) noexcept {
		return xieite::units::CubicKilometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicKilometre operator""_cubicKilometres(const long double value) noexcept {
		return xieite::units::CubicKilometre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMegametre operator""_cubicMegametres(const unsigned long long int value) noexcept {
		return xieite::units::CubicMegametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicMegametre operator""_cubicMegametres(const long double value) noexcept {
		return xieite::units::CubicMegametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicGigametre operator""_cubicGigametres(const unsigned long long int value) noexcept {
		return xieite::units::CubicGigametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicGigametre operator""_cubicGigametres(const long double value) noexcept {
		return xieite::units::CubicGigametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicTerametre operator""_cubicTerametres(const unsigned long long int value) noexcept {
		return xieite::units::CubicTerametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicTerametre operator""_cubicTerametres(const long double value) noexcept {
		return xieite::units::CubicTerametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicPetametre operator""_cubicPetametres(const unsigned long long int value) noexcept {
		return xieite::units::CubicPetametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicPetametre operator""_cubicPetametres(const long double value) noexcept {
		return xieite::units::CubicPetametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicExametre operator""_cubicExametres(const unsigned long long int value) noexcept {
		return xieite::units::CubicExametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicExametre operator""_cubicExametres(const long double value) noexcept {
		return xieite::units::CubicExametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicZettametre operator""_cubicZettametres(const unsigned long long int value) noexcept {
		return xieite::units::CubicZettametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicZettametre operator""_cubicZettametres(const long double value) noexcept {
		return xieite::units::CubicZettametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicYottametre operator""_cubicYottametres(const unsigned long long int value) noexcept {
		return xieite::units::CubicYottametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicYottametre operator""_cubicYottametres(const long double value) noexcept {
		return xieite::units::CubicYottametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicRonnametre operator""_cubicRonnametres(const unsigned long long int value) noexcept {
		return xieite::units::CubicRonnametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicRonnametre operator""_cubicRonnametres(const long double value) noexcept {
		return xieite::units::CubicRonnametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicQuettametre operator""_cubicQuettametres(const unsigned long long int value) noexcept {
		return xieite::units::CubicQuettametre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::CubicQuettametre operator""_cubicQuettametres(const long double value) noexcept {
		return xieite::units::CubicQuettametre(static_cast<double>(value));
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

	[[nodiscard]] constexpr xieite::units::Quectolitre operator""_quectolitres(const unsigned long long int value) noexcept {
		return xieite::units::Quectolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quectolitre operator""_quectolitres(const long double value) noexcept {
		return xieite::units::Quectolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Rontolitre operator""_rontolitres(const unsigned long long int value) noexcept {
		return xieite::units::Rontolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Rontolitre operator""_rontolitres(const long double value) noexcept {
		return xieite::units::Rontolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yoctolitre operator""_yoctolitres(const unsigned long long int value) noexcept {
		return xieite::units::Yoctolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yoctolitre operator""_yoctolitres(const long double value) noexcept {
		return xieite::units::Yoctolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zeptolitre operator""_zeptolitres(const unsigned long long int value) noexcept {
		return xieite::units::Zeptolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zeptolitre operator""_zeptolitres(const long double value) noexcept {
		return xieite::units::Zeptolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Attolitre operator""_attolitres(const unsigned long long int value) noexcept {
		return xieite::units::Attolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Attolitre operator""_attolitres(const long double value) noexcept {
		return xieite::units::Attolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Femtolitre operator""_femtolitres(const unsigned long long int value) noexcept {
		return xieite::units::Femtolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Femtolitre operator""_femtolitres(const long double value) noexcept {
		return xieite::units::Femtolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Picolitre operator""_picolitres(const unsigned long long int value) noexcept {
		return xieite::units::Picolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Picolitre operator""_picolitres(const long double value) noexcept {
		return xieite::units::Picolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Nanolitre operator""_nanolitres(const unsigned long long int value) noexcept {
		return xieite::units::Nanolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Nanolitre operator""_nanolitres(const long double value) noexcept {
		return xieite::units::Nanolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Microlitre operator""_microlitres(const unsigned long long int value) noexcept {
		return xieite::units::Microlitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Microlitre operator""_microlitres(const long double value) noexcept {
		return xieite::units::Microlitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Millilitre operator""_millilitres(const unsigned long long int value) noexcept {
		return xieite::units::Millilitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Millilitre operator""_millilitres(const long double value) noexcept {
		return xieite::units::Millilitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Centilitre operator""_centilitres(const unsigned long long int value) noexcept {
		return xieite::units::Centilitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Centilitre operator""_centilitres(const long double value) noexcept {
		return xieite::units::Centilitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decilitre operator""_decilitres(const unsigned long long int value) noexcept {
		return xieite::units::Decilitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decilitre operator""_decilitres(const long double value) noexcept {
		return xieite::units::Decilitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Litre operator""_litres(const unsigned long long int value) noexcept {
		return xieite::units::Litre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Litre operator""_litres(const long double value) noexcept {
		return xieite::units::Litre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decalitre operator""_decalitres(const unsigned long long int value) noexcept {
		return xieite::units::Decalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Decalitre operator""_decalitres(const long double value) noexcept {
		return xieite::units::Decalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Hectolitre operator""_hectolitres(const unsigned long long int value) noexcept {
		return xieite::units::Hectolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Hectolitre operator""_hectolitres(const long double value) noexcept {
		return xieite::units::Hectolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Kilolitre operator""_kilolitres(const unsigned long long int value) noexcept {
		return xieite::units::Kilolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Kilolitre operator""_kilolitres(const long double value) noexcept {
		return xieite::units::Kilolitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Megalitre operator""_megalitres(const unsigned long long int value) noexcept {
		return xieite::units::Megalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Megalitre operator""_megalitres(const long double value) noexcept {
		return xieite::units::Megalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Gigalitre operator""_gigalitres(const unsigned long long int value) noexcept {
		return xieite::units::Gigalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Gigalitre operator""_gigalitres(const long double value) noexcept {
		return xieite::units::Gigalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Teralitre operator""_teralitres(const unsigned long long int value) noexcept {
		return xieite::units::Teralitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Teralitre operator""_teralitres(const long double value) noexcept {
		return xieite::units::Teralitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Petalitre operator""_petalitres(const unsigned long long int value) noexcept {
		return xieite::units::Petalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Petalitre operator""_petalitres(const long double value) noexcept {
		return xieite::units::Petalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Exalitre operator""_exalitres(const unsigned long long int value) noexcept {
		return xieite::units::Exalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Exalitre operator""_exalitres(const long double value) noexcept {
		return xieite::units::Exalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zettalitre operator""_zettalitres(const unsigned long long int value) noexcept {
		return xieite::units::Zettalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Zettalitre operator""_zettalitres(const long double value) noexcept {
		return xieite::units::Zettalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yottalitre operator""_yottalitres(const unsigned long long int value) noexcept {
		return xieite::units::Yottalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Yottalitre operator""_yottalitres(const long double value) noexcept {
		return xieite::units::Yottalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Ronnalitre operator""_ronnalitres(const unsigned long long int value) noexcept {
		return xieite::units::Ronnalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Ronnalitre operator""_ronnalitres(const long double value) noexcept {
		return xieite::units::Ronnalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quettalitre operator""_quettalitres(const unsigned long long int value) noexcept {
		return xieite::units::Quettalitre(static_cast<double>(value));
	}

	[[nodiscard]] constexpr xieite::units::Quettalitre operator""_quettalitres(const long double value) noexcept {
		return xieite::units::Quettalitre(static_cast<double>(value));
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
