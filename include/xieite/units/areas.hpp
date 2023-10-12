#ifndef XIEITE_HEADER_UNITS_AREAS
#	define XIEITE_HEADER_UNITS_AREAS

#	include <ratio>
#	include "../units/lengths.hpp"

namespace xieite::units {
	using SquareNanometer = std::ratio<1, std::nano::den * std::nano::den>;

	using SquareMicrometer = std::ratio<1, std::micro::den * std::micro::den>;

	using SquareMillimeter = std::ratio<1, std::milli::den * std::milli::den>;

	using SquareCentimeter = std::ratio<1, std::centi::den * std::centi::den>;

	using SquareDecimeter = std::ratio<1, std::deci::den * std::deci::den>;

	using SquareMeter = std::ratio<1, 1>;

	using SquareDecameter = std::ratio<std::deca::num * std::deca::num, 1>;

	using SquareHectometer = std::ratio<std::hecto::num * std::hecto::num, 1>;

	using SquareKilometer = std::ratio<std::kilo::num * std::kilo::num, 1>;

	using SquareMegameter = std::ratio<std::mega::num * std::mega::num, 1>;

	using SquareGigameter = std::ratio<std::giga::num * std::giga::num, 1>;

	using SquareThou = std::ratio<xieite::units::Thou::num * xieite::units::Thou::num, xieite::units::Thou::den * xieite::units::Thou::den>;

	using SquareBarleycorn = std::ratio<xieite::units::Barleycorn::num * xieite::units::Barleycorn::num, xieite::units::Barleycorn::den * xieite::units::Barleycorn::den>;

	using SquareInch = std::ratio<xieite::units::Inch::num * xieite::units::Inch::num, xieite::units::Inch::den * xieite::units::Inch::den>;

	using SquareFoot = std::ratio<xieite::units::Foot::num * xieite::units::Foot::num, xieite::units::Foot::den * xieite::units::Foot::den>;

	using SquareYard = std::ratio<xieite::units::Yard::num * xieite::units::Yard::num, xieite::units::Yard::den * xieite::units::Yard::den>;

	using SquareChain = std::ratio<xieite::units::Chain::num * xieite::units::Chain::num, xieite::units::Chain::den * xieite::units::Chain::den>;

	using SquareFurlong = std::ratio<xieite::units::Furlong::num * xieite::units::Furlong::num, xieite::units::Furlong::den * xieite::units::Furlong::den>;

	using SquareMile = std::ratio<xieite::units::Mile::num * xieite::units::Mile::num, xieite::units::Mile::den * xieite::units::Mile::den>;

	using SquareLeague = std::ratio<xieite::units::League::num * xieite::units::League::num, xieite::units::League::den * xieite::units::League::den>;

	using SquareFathom = std::ratio<xieite::units::Fathom::num * xieite::units::Fathom::num, xieite::units::Fathom::den * xieite::units::Fathom::den>;

	using SquareCable = std::ratio<xieite::units::Cable::num * xieite::units::Cable::num, xieite::units::Cable::den * xieite::units::Cable::den>;

	using SquareNauticalMile = std::ratio<xieite::units::NauticalMile::num * xieite::units::NauticalMile::num, xieite::units::NauticalMile::den * xieite::units::NauticalMile::den>;

	using SquareLink = std::ratio<xieite::units::Link::num * xieite::units::Link::num, xieite::units::Link::den * xieite::units::Link::den>;

	using SquareRod = std::ratio<xieite::units::Rod::num * xieite::units::Rod::num, xieite::units::Rod::den * xieite::units::Rod::den>;

	using Perch = std::ratio<2529285264, 100000000>;

	using Rood = std::ratio<10117141056, 10000000>;

	using Acre = std::ratio<40468564224, 10000000>;
}

#endif
