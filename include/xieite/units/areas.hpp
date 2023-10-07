#ifndef XIEITE_HEADER__UNITS__AREAS
#	define XIEITE_HEADER__UNITS__AREAS

#	include <ratio>

namespace xieite::units {
	using Perch = std::ratio<100000000, 2529285264>;

	using Rood = std::ratio<10000000, 10117141056>;

	using Acre = std::ratio<10000000, 40468564224>;

	using SquareMile = std::ratio<1000000, 2589988110336>;
}

#endif
