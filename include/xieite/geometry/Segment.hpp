#pragma once

#include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	struct Segment final {
		xieite::geometry::Point start;
		xieite::geometry::Point end;
		
		constexpr Segment(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Segment& segment) const noexcept {
			return (this->start == segment.start) && (this->end == segment.end) || (this->start == segment.end) && (this->end == segment.start);
		}
	};
}
