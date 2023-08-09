#ifndef XIEITE_HEADER__GEOMETRY__RAY
#	define XIEITE_HEADER__GEOMETRY__RAY

#	include <cmath>
#	include <limits>
#	include "../geometry/Point.hpp"
#	include "../math/almostEqualSlope.hpp"

namespace xieite::geometry {
	struct Ray {
		xieite::geometry::Point start;
		xieite::geometry::Point end;

		constexpr Ray(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}

		constexpr Ray(const xieite::geometry::Point start, const double angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		constexpr bool operator==(const xieite::geometry::Ray& ray) const noexcept {
			return (this->start == ray.start) && xieite::math::almostEqualSlope((this->start.x == this->end.x) ? std::numeric_limits<double>::infinity() : ((this->end.y - this->start.y) / (this->end.x - this->start.x)), (ray.start.x == ray.end.x) ? std::numeric_limits<double>::infinity() : ((ray.end.y - ray.start.y) / (ray.end.x - ray.start.x)));
		}
	};
}

#endif
