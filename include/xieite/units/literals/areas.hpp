#ifndef XIEITE_HEADER_UNITS_LITERALS_AREAS
#	define XIEITE_HEADER_UNITS_LITERALS_AREAS

#	include "../../units/area.hpp"
#	include "../../units/convert.hpp"

namespace xieite::units::literals {
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
}

#endif
