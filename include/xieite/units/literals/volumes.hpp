#ifndef XIEITE_HEADER_UNITS_LITERALS_VOLUMES
#	define XIEITE_HEADER_UNITS_LITERALS_VOLUMES

#	include "../../units/convert.hpp"
#	include "../../units/volume.hpp"

namespace xieite::units::literals::volumes {
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
}

#endif
