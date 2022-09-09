#pragma once

#include <gcufl/geometry/Line.hpp>
#include <gcufl/geometry/Point.hpp>


namespace gcufl::geometry {
	struct Segment final
	: gcufl::geometry::Line {
		Segment(const gcufl::geometry::Point start, const gcufl::geometry::Point end) noexcept;

		bool operator==(const gcufl::geometry::Segment& other) const noexcept;

		bool operator!=(const gcufl::geometry::Segment& other) const noexcept;

		bool contains(const gcufl::geometry::Point point) const noexcept;

		double length() const noexcept;
	};
};
