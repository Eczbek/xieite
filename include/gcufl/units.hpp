#pragma once

#include <ratio>


namespace gcufl::units::length {
	constexpr std::ratio<176389, 10000000000> twip;
	constexpr std::ratio<254, 10000000> thou;
	constexpr std::ratio<84667, 10000000> barleycorn;
	constexpr std::ratio<254, 10000> inch;
	constexpr std::ratio<3048, 10000> foot;
	constexpr std::ratio<9144, 10000> yard;
	constexpr std::ratio<201168, 10000> chain;
	constexpr std::ratio<201168, 1000> furlong;
	constexpr std::ratio<1609344, 100> mile;
	constexpr std::ratio<4828032, 100> league;
	constexpr std::ratio<1852, 1000> fathom;
	constexpr std::ratio<1852, 10> cable;
	constexpr std::ratio<1852, 1> nauticalMile;
	constexpr std::ratio<201168, 1000000> link;
	constexpr std::ratio<50292, 10000> rod;
}
