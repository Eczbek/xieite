#ifndef XIEITE_HEADER_GEOMETRY_GETAXISINTERCEPT
#	define XIEITE_HEADER_GEOMETRY_GETAXISINTERCEPT

#	include <limits>
#	include "../concepts/LinearShape.hpp"
#	include "../geometry/Point.hpp"
#	include "../geometry/getSlope.hpp"
#	include "../math/almostEqualSlope.hpp"

namespace xieite::geometry {
	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]]
	constexpr xieite::geometry::Point getAxisIntercept(const LinearShape& linearShape, const xieite::geometry::Point origin = xieite::geometry::Point(0.0, 0.0)) noexcept {
		const double slope = xieite::geometry::getSlope(linearShape);
		return xieite::geometry::Point(xieite::math::almostEqualSlope(slope, 0.0) ? linearShape.start.x : (linearShape.start.x - (linearShape.start.y - origin.y) * (linearShape.end.x - linearShape.start.x) / (linearShape.end.y - linearShape.start.y)), xieite::math::almostEqualSlope(slope, std::numeric_limits<double>::infinity()) ? linearShape.start.y : (linearShape.start.y - (linearShape.start.x - origin.x) * (linearShape.end.y - linearShape.start.y) / (linearShape.end.x - linearShape.start.x)));
	}
}

#endif
