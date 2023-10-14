#ifndef XIEITE_HEADER_UNITS_ANGLES
#	define XIEITE_HEADER_UNITS_ANGLES

#	include <ratio>

namespace xieite::units {
	using Radian = std::ratio<1, 1>;

	using Degree = std::ratio<17453292519943295, 1000000000000000000>;
}

#endif
