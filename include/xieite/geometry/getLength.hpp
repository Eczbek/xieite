#ifndef XIEITE_HEADER__GEOMETRY__GET_LENGTH
#	define XIEITE_HEADER__GEOMETRY__GET_LENGTH

#	include <limits>
#	include "../concepts/LinearShape.hpp"
#	include "../geometry/Segment.hpp"
#	include "../geometry/getDistance.hpp"

namespace xieite::geometry {
	constexpr double getLength(const xieite::geometry::Segment& segment) noexcept {
		return xieite::geometry::getDistance(segment.start, segment.end);
	}

	template<xieite::concepts::LinearShape LinearShape>
	constexpr double getLength(const LinearShape&) noexcept {
		return std::numeric_limits<double>::infinity();
	}
}

#endif
