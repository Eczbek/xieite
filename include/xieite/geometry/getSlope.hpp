#ifndef XIEITE_HEADER__GEOMETRY__GET_SLOPE
#	define XIEITE_HEADER__GEOMETRY__GET_SLOPE

#	include <cmath>
#	include <limits>
#	include "../concepts/LinearShape.hpp"
#	include "../geometry/Point.hpp"
#	include "../math/almostEqual.hpp"

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getSlope(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		return xieite::math::almostEqual(point1.x, point2.x) ? std::numeric_limits<double>::infinity() : ((point2.y - point1.y) / (point2.x - point1.x));
	}

	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]]
	constexpr double getSlope(const LinearShape& linearShape) noexcept {
		return xieite::geometry::getSlope(linearShape.start, linearShape.end);
	}
}

#endif
