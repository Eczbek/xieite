#ifndef XIEITE_HEADER__UNITS__LITERALS__VOLUMES
#	define XIEITE_HEADER__UNITS__LITERALS__VOLUMES

#	include "../../units/volumes.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_fluidOunces(const long double value) noexcept {
		return value * xieite::units::FluidOunce::den / xieite::units::FluidOunce::num;
	}

	[[nodiscard]] constexpr double operator""_gills(const long double value) noexcept {
		return value * xieite::units::Gill::den / xieite::units::Gill::num;
	}

	[[nodiscard]] constexpr double operator""_pints(const long double value) noexcept {
		return value * xieite::units::Pint::den / xieite::units::Pint::num;
	}

	[[nodiscard]] constexpr double operator""_quarts(const long double value) noexcept {
		return value * xieite::units::Quart::den / xieite::units::Quart::num;
	}

	[[nodiscard]] constexpr double operator""_gallons(const long double value) noexcept {
		return value * xieite::units::Gallon::den / xieite::units::Gallon::num;
	}
}

#endif
