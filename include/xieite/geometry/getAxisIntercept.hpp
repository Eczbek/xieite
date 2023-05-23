#ifndef XIEITE_HEADER_GEOMETRY_GETAXISINTERCEPT
#	define XIEITE_HEADER_GEOMETRY_GETAXISINTERCEPT

#	include <limits>
#	include <xieite/concepts/LinearShape.hpp>
#	include <xieite/geometry/Point.hpp>
#	include <xieite/geometry/getSlope.hpp>
#	include <xieite/math/approximatelyEqualSlope.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr xieite::geometry::Point getAxisIntercept(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Point origin = xieite::geometry::Point(0.0, 0.0)) noexcept {
		const double slope = xieite::geometry::getSlope(linearShape);
		return xieite::geometry::Point(xieite::math::approximatelyEqualSlope(slope, 0.0) ? linearShape.start.x : (linearShape.start.x - (linearShape.start.y - origin.y) * (linearShape.end.x - linearShape.start.x) / (linearShape.end.y - linearShape.start.y)), xieite::math::approximatelyEqualSlope(slope, std::numeric_limits<double>::infinity()) ? linearShape.start.y : (linearShape.start.y - (start.x - origin.x) * (linearShape.end.y - linearShape.start.y) / (linearShape.end.x - linearShape.start.x)));
	}
}

#endif
