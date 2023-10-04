#ifndef XIEITE_HEADER__GEOMETRY__LINE
#	define XIEITE_HEADER__GEOMETRY__LINE

#	include <cmath>
#	include <limits>
#	include "../geometry/Point.hpp"
#	include "../math/almostEqual.hpp"
#	include "../math/almostEqualSlope.hpp"

namespace xieite::geometry {
	struct Line {
		xieite::geometry::Point start;
		xieite::geometry::Point end;

		constexpr Line(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}

		constexpr Line(const xieite::geometry::Point start, const double angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		friend constexpr bool operator==(const xieite::geometry::Line& line1, const xieite::geometry::Line& line2) noexcept {
			return (line1.containsPoint(line2.start) || line1.containsPoint(line2.end)) && xieite::math::almostEqualSlope(line1.slope(), line2.slope());
		}

		constexpr double angle() const noexcept {
			return this->start.angleTo(this->end);
		}

		constexpr bool containsPoint(const xieite::geometry::Point point) const noexcept {
			return xieite::math::almostEqual((this->end.x - this->start.x) * (point.y - this->start.y), (this->end.y - this->start.y) * (point.x - this->start.x));
		}

		constexpr double length() const noexcept {
			return std::numeric_limits<double>::infinity();
		}

		constexpr double slope() const noexcept {
			return this->start.slopeTo(this->end);
		}
	};
}

#endif
