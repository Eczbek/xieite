#ifndef XIEITE_HEADER_GEOMETRY_RAY
#	define XIEITE_HEADER_GEOMETRY_RAY

#	include <cmath>
#	include <limits>
#	include <xieite/geometry/Point.hpp>
#	include <xieite/math/approximatelyEqualSlope.hpp>

namespace xieite::geometry {
	struct Ray final {
		xieite::geometry::Point start;
		xieite::geometry::Point end;

		constexpr Ray(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}

		constexpr Ray(const xieite::geometry::Point start, const double angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Ray& ray) const noexcept {
			return (this->start == ray.start) && xieite::math::approximatelyEqualSlope((this->start.x == this->end.x) ? std::numeric_limits<double>::infinity() : ((this->end.y - this->start.y) / (this->end.x - this->start.x)), (ray.start.x == ray.end.x) ? std::numeric_limits<double>::infinity() : ((ray.end.y - ray.start.y) / (ray.end.x - ray.start.x)));
		}
	};
}

#endif
