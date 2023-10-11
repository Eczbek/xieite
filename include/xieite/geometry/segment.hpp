#ifndef XIEITE_HEADER_GEOMETRY_SEGMENT
#	define XIEITE_HEADER_GEOMETRY_SEGMENT

#	include "../geometry/point.hpp"
#	include "../math/almost_equal.hpp"

namespace xieite::geometry {
	struct Segment {
		xieite::geometry::Point start;
		xieite::geometry::Point end;

		constexpr Segment(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Segment& segment1, const xieite::geometry::Segment& segment2) noexcept {
			return (segment1.start == segment2.start) && (segment1.end == segment2.end) || (segment1.start == segment2.end) && (segment1.end == segment2.start);
		}

		[[nodiscard]] constexpr double angle() const noexcept {
			return this->start.angleTo(this->end);
		}

		[[nodiscard]] constexpr bool containsPoint(const xieite::geometry::Point point) const noexcept {
			return xieite::math::almostEqual(this->start.distanceTo(point) + this->end.distanceTo(point), this->length());
		}

		[[nodiscard]] constexpr double length() const noexcept {
			return this->start.distanceTo(this->end);
		}

		[[nodiscard]] constexpr double slope() const noexcept {
			return this->start.slopeTo(this->end);
		}
	};
}

#endif
