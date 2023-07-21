#ifndef XIEITE_HEADER_GEOMETRY_GETSIDES
#	define XIEITE_HEADER_GEOMETRY_GETSIDES

#	include <cstddef>
#	include <vector>
#	include <xieite/geometry/Polygon.hpp>
#	include <xieite/geometry/Segment.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Segment> getSides(const xieite::geometry::Polygon& polygon) noexcept {
		std::vector<xieite::geometry::Segment> sides;
		const std::size_t pointsSize = polygon.points.size();
		for (std::size_t i = 0; i < pointsSize; ++i) {
			sides.push_back(xieite::geometry::Segment(polygon.points[i], polygon.points[(i + 1) % pointsSize]));
		}
		return sides;
	}
}

#endif
