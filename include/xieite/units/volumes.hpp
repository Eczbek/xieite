#ifndef XIEITE_HEADER_UNITS_VOLUMES
#	define XIEITE_HEADER_UNITS_VOLUMES

#	include <ratio>

namespace xieite::units {
	using Attolitre = std::atto;

	using Femtolitre = std::femto;

	using Picolitre = std::pico;

	using Nanolitre = std::nano;

	using Microlitre = std::micro;

	using Millilitre = std::milli;

	using Centilitre = std::centi;

	using Decilitre = std::deci;

	using Litre = std::ratio<1, 1>;

	using Decalitre = std::deca;

	using Hectolitre = std::hecto;

	using Kilolitre = std::kilo;

	using Megalitre = std::mega;

	using Gigalitre = std::giga;

	using Teralitre = std::tera;

	using Petalitre = std::peta;

	using Exalitre = std::exa;

	using FluidOunce = std::ratio<2841306, 100000000>;

	using Pint = std::ratio<5682612, 10000000>;

	using Quart = std::ratio<1136522, 1000000>;

	using Gallon = std::ratio<454609, 100000>;

	using Gill = std::ratio<1182941, 10000000>;
}

#endif
