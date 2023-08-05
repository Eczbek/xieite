#ifndef XIEITE_HEADER__UNITS__VOLUMES
#	define XIEITE_HEADER__UNITS__VOLUMES

#	include <ratio>

namespace xieite::units::volumes {
	inline constexpr std::ratio<284130625, 10000000> fluidOunce;
	inline constexpr std::ratio<1420653125, 10000000> gill;
	inline constexpr std::ratio<56826125, 100000> pint;
	inline constexpr std::ratio<11365225, 10000> quart;
	inline constexpr std::ratio<454609, 100> gallon;
}

#endif
