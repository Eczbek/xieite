#ifndef XIEITE_HEADER_GEOMETRY_GETLENGTH
#	define XIEITE_HEADER_GEOMETRY_GETLENGTH

#	include <limits>
#	include "../concepts/LinearShape.hpp"
#	include "../geometry/Segment.hpp"
#	include "../geometry/getDistance.hpp"

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getLength(const xieite::geometry::Segment& segment) noexcept {
		return xieite::geometry::getDistance(segment.start, segment.end);
	}

	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]]
	constexpr double getLength(const LinearShape&) noexcept {
		return std::numeric_limits<double>::infinity();
	}
}

#endif
