#ifndef XIEITE_HEADER__UNITS__LENGTHS
#	define XIEITE_HEADER__UNITS__LENGTHS

#	include <ratio>

namespace xieite::units::lengths {
	inline constexpr std::ratio<176389, 10000000000> twip;
	inline constexpr std::ratio<254, 10000000> thou;
	inline constexpr std::ratio<84667, 10000000> barleycorn;
	inline constexpr std::ratio<254, 10000> inch;
	inline constexpr std::ratio<3048, 10000> foot;
	inline constexpr std::ratio<9144, 10000> yard;
	inline constexpr std::ratio<201168, 10000> chain;
	inline constexpr std::ratio<201168, 1000> furlong;
	inline constexpr std::ratio<1609344, 100> mile;
	inline constexpr std::ratio<4828032, 100> league;
	inline constexpr std::ratio<1852, 1000> fathom;
	inline constexpr std::ratio<1852, 10> cable;
	inline constexpr std::ratio<1852, 1> nauticalMile;
	inline constexpr std::ratio<201168, 1000000> link;
	inline constexpr std::ratio<50292, 10000> rod;
}

#endif
