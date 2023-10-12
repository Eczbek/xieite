#ifndef XIEITE_HEADER_UNITS_LITERALS_VOLUMES
#	define XIEITE_HEADER_UNITS_LITERALS_VOLUMES

#	include "../../units/volumes.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_attolitres(const long double value) noexcept {
		return value * xieite::units::Attolitre::num / xieite::units::Attolitre::den;
	}

	[[nodiscard]] constexpr double operator""_attolitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Attolitre::num / xieite::units::Attolitre::den;
	}

	[[nodiscard]] constexpr double operator""_femtolitres(const long double value) noexcept {
		return value * xieite::units::Femtolitre::num / xieite::units::Femtolitre::den;
	}

	[[nodiscard]] constexpr double operator""_femtolitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Femtolitre::num / xieite::units::Femtolitre::den;
	}

	[[nodiscard]] constexpr double operator""_picolitres(const long double value) noexcept {
		return value * xieite::units::Picolitre::num / xieite::units::Picolitre::den;
	}

	[[nodiscard]] constexpr double operator""_picolitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Picolitre::num / xieite::units::Picolitre::den;
	}

	[[nodiscard]] constexpr double operator""_nanolitres(const long double value) noexcept {
		return value * xieite::units::Nanolitre::num / xieite::units::Nanolitre::den;
	}

	[[nodiscard]] constexpr double operator""_nanolitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Nanolitre::num / xieite::units::Nanolitre::den;
	}

	[[nodiscard]] constexpr double operator""_microlitres(const long double value) noexcept {
		return value * xieite::units::Microlitre::num / xieite::units::Microlitre::den;
	}

	[[nodiscard]] constexpr double operator""_microlitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Microlitre::num / xieite::units::Microlitre::den;
	}

	[[nodiscard]] constexpr double operator""_millilitres(const long double value) noexcept {
		return value * xieite::units::Millilitre::num / xieite::units::Millilitre::den;
	}

	[[nodiscard]] constexpr double operator""_millilitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Millilitre::num / xieite::units::Millilitre::den;
	}

	[[nodiscard]] constexpr double operator""_centilitres(const long double value) noexcept {
		return value * xieite::units::Centilitre::num / xieite::units::Centilitre::den;
	}

	[[nodiscard]] constexpr double operator""_centilitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Centilitre::num / xieite::units::Centilitre::den;
	}

	[[nodiscard]] constexpr double operator""_decilitres(const long double value) noexcept {
		return value * xieite::units::Decilitre::num / xieite::units::Decilitre::den;
	}

	[[nodiscard]] constexpr double operator""_decilitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Decilitre::num / xieite::units::Decilitre::den;
	}

	[[nodiscard]] constexpr double operator""_litres(const long double value) noexcept {
		return value * xieite::units::Litre::num / xieite::units::Litre::den;
	}

	[[nodiscard]] constexpr double operator""_litres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Litre::num / xieite::units::Litre::den;
	}

	[[nodiscard]] constexpr double operator""_decalitres(const long double value) noexcept {
		return value * xieite::units::Decalitre::num / xieite::units::Decalitre::den;
	}

	[[nodiscard]] constexpr double operator""_decalitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Decalitre::num / xieite::units::Decalitre::den;
	}

	[[nodiscard]] constexpr double operator""_hectolitres(const long double value) noexcept {
		return value * xieite::units::Hectolitre::num / xieite::units::Hectolitre::den;
	}

	[[nodiscard]] constexpr double operator""_hectolitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Hectolitre::num / xieite::units::Hectolitre::den;
	}

	[[nodiscard]] constexpr double operator""_kilolitres(const long double value) noexcept {
		return value * xieite::units::Kilolitre::num / xieite::units::Kilolitre::den;
	}

	[[nodiscard]] constexpr double operator""_kilolitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Kilolitre::num / xieite::units::Kilolitre::den;
	}

	[[nodiscard]] constexpr double operator""_megalitres(const long double value) noexcept {
		return value * xieite::units::Megalitre::num / xieite::units::Megalitre::den;
	}

	[[nodiscard]] constexpr double operator""_megalitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Megalitre::num / xieite::units::Megalitre::den;
	}

	[[nodiscard]] constexpr double operator""_gigalitres(const long double value) noexcept {
		return value * xieite::units::Gigalitre::num / xieite::units::Gigalitre::den;
	}

	[[nodiscard]] constexpr double operator""_gigalitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Gigalitre::num / xieite::units::Gigalitre::den;
	}

	[[nodiscard]] constexpr double operator""_teralitres(const long double value) noexcept {
		return value * xieite::units::Teralitre::num / xieite::units::Teralitre::den;
	}

	[[nodiscard]] constexpr double operator""_teralitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Teralitre::num / xieite::units::Teralitre::den;
	}

	[[nodiscard]] constexpr double operator""_petalitres(const long double value) noexcept {
		return value * xieite::units::Petalitre::num / xieite::units::Petalitre::den;
	}

	[[nodiscard]] constexpr double operator""_petalitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Petalitre::num / xieite::units::Petalitre::den;
	}

	[[nodiscard]] constexpr double operator""_exalitres(const long double value) noexcept {
		return value * xieite::units::Exalitre::num / xieite::units::Exalitre::den;
	}

	[[nodiscard]] constexpr double operator""_exalitres(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Exalitre::num / xieite::units::Exalitre::den;
	}

	[[nodiscard]] constexpr double operator""_fluidOunces(const long double value) noexcept {
		return value * xieite::units::FluidOunce::num / xieite::units::FluidOunce::den;
	}

	[[nodiscard]] constexpr double operator""_fluidOunces(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::FluidOunce::num / xieite::units::FluidOunce::den;
	}

	[[nodiscard]] constexpr double operator""_pints(const long double value) noexcept {
		return value * xieite::units::Pint::num / xieite::units::Pint::den;
	}

	[[nodiscard]] constexpr double operator""_pints(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Pint::num / xieite::units::Pint::den;
	}

	[[nodiscard]] constexpr double operator""_quarts(const long double value) noexcept {
		return value * xieite::units::Quart::num / xieite::units::Quart::den;
	}

	[[nodiscard]] constexpr double operator""_quarts(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Quart::num / xieite::units::Quart::den;
	}

	[[nodiscard]] constexpr double operator""_gallons(const long double value) noexcept {
		return value * xieite::units::Gallon::num / xieite::units::Gallon::den;
	}

	[[nodiscard]] constexpr double operator""_gallons(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Gallon::num / xieite::units::Gallon::den;
	}

	[[nodiscard]] constexpr double operator""_gills(const long double value) noexcept {
		return value * xieite::units::Gill::num / xieite::units::Gill::den;
	}

	[[nodiscard]] constexpr double operator""_gills(const unsigned long long int value) noexcept {
		return static_cast<double>(value) * xieite::units::Gill::num / xieite::units::Gill::den;
	}
}

#endif
