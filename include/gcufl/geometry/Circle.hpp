#pragma once

#include <gcufl/geometry/Ellipse.hpp>
#include <gcufl/geometry/Point.hpp>
#include <gcufl/geometry/Polygon.hpp>


namespace gcufl::geometry {
	struct Circle final
	: gcufl::geometry::Ellipse {
		Circle(const gcufl::geometry::Point center, const double radius) noexcept;

		bool operator==(const gcufl::geometry::Circle& other) const noexcept;

		bool operator!=(const gcufl::geometry::Circle& other) const noexcept;

		double area() const noexcept;

		gcufl::geometry::Polygon boundingBox() const noexcept;

		bool contains(const gcufl::geometry::Point point) const noexcept;

		double perimeter() const noexcept;
	};
}
