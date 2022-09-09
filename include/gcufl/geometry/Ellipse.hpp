#pragma once

#include <gcufl/geometry/Point.hpp>
#include <gcufl/geometry/Polygon.hpp>


namespace gcufl::geometry {
	struct Ellipse {
		gcufl::geometry::Point center;
		gcufl::geometry::Point radius;
		double rotation;

		Ellipse(const gcufl::geometry::Point center, const gcufl::geometry::Point radius, const double rotation = 0) noexcept;

		virtual bool operator==(const gcufl::geometry::Ellipse& other) const noexcept;

		virtual bool operator!=(const gcufl::geometry::Ellipse& other) const noexcept;

		virtual double area() const noexcept;

		virtual gcufl::geometry::Polygon boundingBox() const noexcept;

		virtual bool contains(const gcufl::geometry::Point point) const noexcept;

		virtual std::vector<gcufl::geometry::Point> intersections(const gcufl::geometry::Line& line) const noexcept;

		virtual double perimeter() const noexcept;

		gcufl::geometry::Ellipse rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept;
	};
}
