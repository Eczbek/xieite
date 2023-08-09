#ifndef XIEITE_HEADER__GEOMETRY__SEGMENT
#	define XIEITE_HEADER__GEOMETRY__SEGMENT

#	include "../geometry/Point.hpp"

namespace xieite::geometry {
	struct Segment {
		xieite::geometry::Point start;
		xieite::geometry::Point end;
		
		constexpr Segment(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}

		constexpr bool operator==(const xieite::geometry::Segment& segment) const noexcept {
			return (this->start == segment.start) && (this->end == segment.end) || (this->start == segment.end) && (this->end == segment.start);
		}
	};
}

#endif
