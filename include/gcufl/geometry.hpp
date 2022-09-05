#pragma once

#include <optional>
#include <vector>


namespace gcufl {
	namespace geometry {
		struct Point {
			double x;
			double y;

			Point(const double x = 0, const double y = 0) noexcept;

			bool operator==(const gcufl::geometry::Point other) const noexcept;

			bool operator!=(const gcufl::geometry::Point other) const noexcept;

			gcufl::geometry::Point rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept;
		};

		struct Line {
			gcufl::geometry::Point start;
			gcufl::geometry::Point end;

			Line(const gcufl::geometry::Point intersection1, const gcufl::geometry::Point intersection2) noexcept;

			Line(const gcufl::geometry::Point intersection, const double angle) noexcept;

			bool operator==(const gcufl::geometry::Line& other) const noexcept;

			bool operator!=(const gcufl::geometry::Line& other) const noexcept;

			double slope() const noexcept;

			double interceptX() const noexcept;

			double interceptY() const noexcept;

			double angle() const noexcept;

			std::optional<gcufl::geometry::Point> intersection(const gcufl::geometry::Line& other) const noexcept;

			double length() const noexcept;

			virtual bool contains(const gcufl::geometry::Point point) const noexcept;

			gcufl::geometry::Line rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0));
		};

		struct Ray
		: gcufl::geometry::Line {
			Ray(const gcufl::geometry::Point start, const gcufl::geometry::Point intersection) noexcept;

			Ray(const gcufl::geometry::Point start, const double angle) noexcept;

			bool operator==(const gcufl::geometry::Ray& other) const noexcept;

			bool operator!=(const gcufl::geometry::Ray& other) const noexcept;

			bool contains(const gcufl::geometry::Point point) const noexcept;
		};

		struct Segment
		: gcufl::geometry::Line {
			Segment(const gcufl::geometry::Point start, const gcufl::geometry::Point end) noexcept;

			bool operator==(const gcufl::geometry::Segment& other) const noexcept;

			bool operator!=(const gcufl::geometry::Segment& other) const noexcept;

			double length() const noexcept;

			bool contains(const gcufl::geometry::Point point) const noexcept;
		};

		struct Polygon {
			std::vector<gcufl::geometry::Point> points;

			Polygon(const std::vector<gcufl::geometry::Point>& points) noexcept;

			bool operator==(const gcufl::geometry::Polygon& other) const noexcept;

			bool operator!=(const gcufl::geometry::Polygon& other) const noexcept;

			double area() const noexcept;

			double perimeter() const noexcept;

			std::vector<gcufl::geometry::Segment> sides() const noexcept;

			bool contains(const gcufl::geometry::Point point) const noexcept;

			gcufl::geometry::Polygon rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept;
		};

		struct Ellipse {
			gcufl::geometry::Point center;
			gcufl::geometry::Point radius;
			double rotation;

			Ellipse(const gcufl::geometry::Point center, const gcufl::geometry::Point radius, const double rotation = 0) noexcept;

			bool operator==(const gcufl::geometry::Ellipse& other) const noexcept;

			bool operator!=(const gcufl::geometry::Ellipse& other) const noexcept;

			double area() const noexcept;

			double perimeter() const noexcept;

			bool contains(const gcufl::geometry::Point point) const noexcept;

			std::vector<gcufl::geometry::Point> intersections(const gcufl::geometry::Line& line) const noexcept;

			std::vector<gcufl::geometry::Point> intersections(const gcufl::geometry::Ellipse& other) const noexcept;

			gcufl::geometry::Ellipse rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept;

			gcufl::geometry::Polygon boundingBox() const noexcept;
		};

		struct Circle
		: gcufl::geometry::Ellipse {
			Circle(const gcufl::geometry::Point center, const double radius) noexcept;

			bool operator==(const gcufl::geometry::Circle& other) const noexcept;

			bool operator!=(const gcufl::geometry::Circle& other) const noexcept;

			double area() const noexcept;

			double perimeter() const noexcept;

			bool contains(const gcufl::geometry::Point point) const noexcept;

			gcufl::geometry::Circle rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept;
		};
	}
}
