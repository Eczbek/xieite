#ifndef XIEITE_HEADER__UNITS__VOLUMES
#	define XIEITE_HEADER__UNITS__VOLUMES

#	include <ratio>

namespace xieite::units {
	using FluidOunce = std::ratio<10000000, 284130625>;

	using Gill = std::ratio<10000000, 1420653125>;

	using Pint = std::ratio<100000, 56826125>;

	using Quart = std::ratio<10000, 11365225>;

	using Gallon = std::ratio<100, 454609> gallon;
}

#endif
