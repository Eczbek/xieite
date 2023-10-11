#ifndef XIEITE_HEADER_UNITS_LITERALS_LENGTHS
#	define XIEITE_HEADER_UNITS_LITERALS_LENGTHS

#	include "../../units/lengths.hpp"

namespace xieite::units::literals {
	[[nodiscard]] constexpr double operator""_twips(const long double value) noexcept {
		return value * xieite::units::Twip::den / xieite::units::Twip::num;
	}

	[[nodiscard]] constexpr double operator""_thous(const long double value) noexcept {
		return value * xieite::units::Thou::den / xieite::units::Thou::num;
	}

	[[nodiscard]] constexpr double operator""_barleycorns(const long double value) noexcept {
		return value * xieite::units::Barleycorn::den / xieite::units::Barleycorn::num;
	}

	[[nodiscard]] constexpr double operator""_inches(const long double value) noexcept {
		return value * xieite::units::Inch::den / xieite::units::Inch::num;
	}

	[[nodiscard]] constexpr double operator""_feet(const long double value) noexcept {
		return value * xieite::units::Foot::den / xieite::units::Foot::num;
	}

	[[nodiscard]] constexpr double operator""_yards(const long double value) noexcept {
		return value * xieite::units::Yard::den / xieite::units::Yard::num;
	}

	[[nodiscard]] constexpr double operator""_chains(const long double value) noexcept {
		return value * xieite::units::Chain::den / xieite::units::Chain::num;
	}

	[[nodiscard]] constexpr double operator""_furlongs(const long double value) noexcept {
		return value * xieite::units::Furlong::den / xieite::units::Furlong::num;
	}

	[[nodiscard]] constexpr double operator""_miles(const long double value) noexcept {
		return value * xieite::units::Mile::den / xieite::units::Mile::num;
	}

	[[nodiscard]] constexpr double operator""_leagues(const long double value) noexcept {
		return value * xieite::units::League::den / xieite::units::League::num;
	}

	[[nodiscard]] constexpr double operator""_fathoms(const long double value) noexcept {
		return value * xieite::units::Fathom::den / xieite::units::Fathom::num;
	}

	[[nodiscard]] constexpr double operator""_cables(const long double value) noexcept {
		return value * xieite::units::Cable::den / xieite::units::Cable::num;
	}

	[[nodiscard]] constexpr double operator""_nauticalMiles(const long double value) noexcept {
		return value * xieite::units::NauticalMile::den / xieite::units::NauticalMile::num;
	}

	[[nodiscard]] constexpr double operator""_links(const long double value) noexcept {
		return value * xieite::units::Link::den / xieite::units::Link::num;
	}

	[[nodiscard]] constexpr double operator""_rods(const long double value) noexcept {
		return value * xieite::units::Rod::den / xieite::units::Rod::num;
	}
}

#endif
