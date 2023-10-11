#ifndef XIEITE_HEADER_GEOMETRY_LINE
#	define XIEITE_HEADER_GEOMETRY_LINE

#	include <cmath>
#	include <limits>
#	include "../geometry/point.hpp"
#	include "../math/almost_equal.hpp"

namespace xieite::geometry {
	struct Line {
		xieite::geometry::Point start;
		xieite::geometry::Point end;

		constexpr Line(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}

		constexpr Line(const xieite::geometry::Point start, const double angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Line& line1, const xieite::geometry::Line& line2) noexcept {
			return line1.containsPoint(line2.start) && line1.containsPoint(line2.end);
		}

		[[nodiscard]] constexpr double angle() const noexcept {
			return this->start.angleTo(this->end);
		}

		[[nodiscard]] constexpr bool containsPoint(const xieite::geometry::Point point) const noexcept {
			return xieite::math::almostEqual((this->end.x - this->start.x) * (point.y - this->start.y), (this->end.y - this->start.y) * (point.x - this->start.x));
		}

		[[nodiscard]] constexpr double length() const noexcept {
			return std::numeric_limits<double>::infinity();
		}

		[[nodiscard]] constexpr double slope() const noexcept {
			return this->start.slopeTo(this->end);
		}
	};
}

#endif
