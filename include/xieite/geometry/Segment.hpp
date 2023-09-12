#ifndef XIEITE_HEADER__GEOMETRY__SEGMENT
#	define XIEITE_HEADER__GEOMETRY__SEGMENT

#	include "../geometry/Point.hpp"
#	include "../math/almostEqual.hpp"

namespace xieite::geometry {
	struct Segment {
		xieite::geometry::Point start;
		xieite::geometry::Point end;
		
		constexpr Segment(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}

		friend constexpr bool operator==(const xieite::geometry::Segment& segment1, const xieite::geometry::Segment& segment2) noexcept {
			return (segment1.start == segment2.start) && (segment1.end == segment2.end) || (segment1.start == segment2.end) && (segment1.end == segment2.start);
		}
		
		constexpr double angle() const noexcept {
			return this->start.angleTo(this->end);
		}
		
		constexpr bool containsPoint(const xieite::geometry::Point point) const noexcept {
			return xieite::math::almostEqual(point.distanceTo(this->start) + point.distanceTo(this->end), this->length());
		}
		
		constexpr double length() const noexcept {
			return this->start.distanceTo(this->end);
		}
		
		constexpr double slope() const noexcept {
			return this->start.slopeTo(this->end);
		}
	};
}

#endif
