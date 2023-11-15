#ifndef XIEITE_HEADER_UNITS_LITERALS_VOLUMES
#	define XIEITE_HEADER_UNITS_LITERALS_VOLUMES

#	include "../../units/convert.hpp"
#	include "../../units/volume.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_quectolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::quectolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_quectolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::quectolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_rontolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::rontolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_rontolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::rontolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_yoctolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::yoctolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_yoctolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::yoctolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_zeptolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::zeptolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_zeptolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::zeptolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_attolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::attolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_attolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::attolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_femtolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::femtolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_femtolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::femtolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_picolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::picolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_picolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::picolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_nanolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::nanolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_nanolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::nanolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_microlitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::microlitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_microlitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::microlitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_millilitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::millilitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_millilitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::millilitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_centilitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::centilitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_centilitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::centilitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_decilitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::decilitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_decilitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::decilitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_litres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::litre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_litres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::litre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_decalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::decalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_decalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::decalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_hectolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::hectolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_hectolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::hectolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_kilolitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::kilolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_kilolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::kilolitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_megalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::megalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_megalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::megalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_gigalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::gigalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_gigalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::gigalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_teralitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::teralitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_teralitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::teralitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_petalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::petalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_petalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::petalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_exalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::exalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_exalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::exalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_zettalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::zettalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_zettalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::zettalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_yottalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::yottalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_yottalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::yottalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_ronnalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::ronnalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_ronnalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::ronnalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_quettalitres(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::quettalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_quettalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::quettalitre, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_fluidOunces(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::fluidOunce, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_fluidOunces(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::fluidOunce, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_gills(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::gill, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_gills(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::gill, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_cups(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cup, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_cups(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::cup, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_pints(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::pint, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_pints(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::pint, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_quarts(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::quart, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_quarts(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::quart, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_gallons(const long double value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::gallon, xieite::units::Volume::litre);
	}

	[[nodiscard]] constexpr double operator""_gallons(const unsigned long long int value) noexcept {
		return xieite::units::convert(value, xieite::units::Volume::gallon, xieite::units::Volume::litre);
	}
}

#endif
