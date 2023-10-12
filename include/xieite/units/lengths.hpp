#ifndef XIEITE_HEADER_UNITS_LENGTHS
#	define XIEITE_HEADER_UNITS_LENGTHS

#	include <ratio>

namespace xieite::units {
	using Attometer = std::atto;

	using Femtometer = std::femto;

	using Picometer = std::pico;

	using Nanometer = std::nano;

	using Micrometer = std::micro;

	using Millimeter = std::milli;

	using Centimeter = std::centi;

	using Decimeter = std::deci;

	using Meter = std::ratio<1, 1>;

	using Decameter = std::deca;

	using Hectometer = std::hecto;

	using Kilometer = std::kilo;

	using Megameter = std::mega;

	using Gigameter = std::giga;

	using Terameter = std::tera;

	using Petameter = std::peta;

	using Exameter = std::exa;

	using Twip = std::ratio<176389, 10000000000>;

	using Thou = std::ratio<254, 10000000>;

	using Barleycorn = std::ratio<84667, 10000000>;

	using Inch = std::ratio<254, 10000>;

	using Foot = std::ratio<3048, 10000>;

	using Yard = std::ratio<9144, 10000>;

	using Chain = std::ratio<201168, 10000>;

	using Furlong = std::ratio<201168, 1000>;

	using Mile = std::ratio<1609344, 1000>;

	using League = std::ratio<4828032, 100>;

	using Fathom = std::ratio<1852, 1000>;

	using Cable = std::ratio<1852, 10>;

	using NauticalMile = std::ratio<1852, 1>;

	using Link = std::ratio<201168, 1000000>;

	using Rod = std::ratio<50292, 10000>;
}

#endif
