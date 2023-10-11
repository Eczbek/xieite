#ifndef XIEITE_HEADER_UNITS_LITERALS_AREAS
#	define XIEITE_HEADER_UNITS_LITERALS_AREAS

#	include "../../units/areas.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_perches(const long double value) noexcept {
		return value * xieite::units::Perch::den / xieite::units::Perch::num;
	}

	[[nodiscard]] constexpr double operator""_roods(const long double value) noexcept {
		return value * xieite::units::Rood::den / xieite::units::Rood::num;
	}

	[[nodiscard]] constexpr double operator""_acres(const long double value) noexcept {
		return value * xieite::units::Acre::den / xieite::units::Acre::num;
	}

	[[nodiscard]] constexpr double operator""_squareMiles(const long double value) noexcept {
		return value * xieite::units::SquareMile::den / xieite::units::SquareMile::num;
	}
}

#endif
