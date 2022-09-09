#pragma once

#include <gcufl/geometry/Point.hpp>
#include <optional>


namespace gcufl::geometry {
	struct Line {
		gcufl::geometry::Point start;
		gcufl::geometry::Point end;

		Line(const gcufl::geometry::Point intersection1, const gcufl::geometry::Point intersection2) noexcept;

		Line(const gcufl::geometry::Point intersection, const double angle) noexcept;

		virtual bool operator==(const gcufl::geometry::Line& other) const noexcept;

		virtual bool operator!=(const gcufl::geometry::Line& other) const noexcept;

		double angle() const noexcept;

		virtual bool contains(const gcufl::geometry::Point point) const noexcept;

		std::optional<gcufl::geometry::Point> intersection(const gcufl::geometry::Line& other) const noexcept;

		virtual double length() const noexcept;
		
		gcufl::geometry::Line rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0));

		double slope() const noexcept;
	};
}
