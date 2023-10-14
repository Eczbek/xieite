#ifndef XIEITE_HEADER_UNITS_LITERALS_VOLUMES
#	define XIEITE_HEADER_UNITS_LITERALS_VOLUMES

#	include "../../units/convert.hpp"
#	include "../../units/volumes.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_attolitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Attolitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_attolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Attolitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_femtolitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Femtolitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_femtolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Femtolitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_picolitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Picolitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_picolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Picolitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_nanolitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Nanolitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_nanolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Nanolitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_microlitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Microlitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_microlitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Microlitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_millilitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Millilitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_millilitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Millilitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_centilitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Centilitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_centilitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Centilitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_decilitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Decilitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_decilitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Decilitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_litres(const long double value) noexcept {
		return value;
	}

	[[nodiscard]] constexpr double operator""_litres(const unsigned long long int value) noexcept {
		return static_cast<double>(value);
	}

	[[nodiscard]] constexpr double operator""_decalitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Decalitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_decalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Decalitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_hectolitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Hectolitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_hectolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Hectolitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_kilolitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Kilolitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_kilolitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Kilolitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_megalitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Megalitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_megalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Megalitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_gigalitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Gigalitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_gigalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Gigalitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_teralitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Teralitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_teralitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Teralitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_petalitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Petalitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_petalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Petalitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_exalitres(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Exalitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_exalitres(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Exalitre, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_fluidOunces(const long double value) noexcept {
		return xieite::units::convert<xieite::units::FluidOunce, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_fluidOunces(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::FluidOunce, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_pints(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Pint, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_pints(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Pint, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_quarts(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Quart, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_quarts(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Quart, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_gallons(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Gallon, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_gallons(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Gallon, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_gills(const long double value) noexcept {
		return xieite::units::convert<xieite::units::Gill, xieite::units::Litre>(value);
	}

	[[nodiscard]] constexpr double operator""_gills(const unsigned long long int value) noexcept {
		return xieite::units::convert<xieite::units::Gill, xieite::units::Litre>(value);
	}
}

#endif
