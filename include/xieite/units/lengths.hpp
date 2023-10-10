#pragma once

#include <ratio>

namespace xieite::units {
	using Twip = std::ratio<10000000000, 176389>;

	using Thou = std::ratio<10000000, 254>;

	using Barleycorn = std::ratio<10000000, 84667>;

	using Inch = std::ratio<10000, 254>;

	using Foot = std::ratio<10000, 3048>;

	using Yard = std::ratio<10000, 9144>;

	using Chain = std::ratio<10000, 201168>;

	using Furlong = std::ratio<1000, 201168>;

	using Mile = std::ratio<1000, 1609344>;

	using League = std::ratio<100, 4828032>;

	using Fathom = std::ratio<1000, 1852>;

	using Cable = std::ratio<10, 1852>;

	using NauticalMile = std::ratio<1, 1852>;

	using Link = std::ratio<1000000, 201168>;

	using Rod = std::ratio<10000, 50292>;
}
