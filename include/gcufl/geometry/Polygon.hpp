#pragma once

#include <gcufl/geometry/Point.hpp>
#include <gcufl/geometry/Segment.hpp>
#include <vector>


namespace gcufl::geometry {
	struct Polygon {
		std::vector<gcufl::geometry::Point> points;

		Polygon(const std::vector<gcufl::geometry::Point>& points) noexcept;

		virtual bool operator==(const gcufl::geometry::Polygon& other) const noexcept;

		virtual bool operator!=(const gcufl::geometry::Polygon& other) const noexcept;

		virtual double area() const noexcept;

		virtual bool contains(const gcufl::geometry::Point point) const noexcept;

		virtual double perimeter() const noexcept;

		gcufl::geometry::Polygon rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept;

		std::vector<gcufl::geometry::Segment> sides() const noexcept;
	};
}
