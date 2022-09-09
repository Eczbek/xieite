#pragma once

#include <gcufl/geometry/Line.hpp>
#include <gcufl/geometry/Point.hpp>


namespace gcufl::geometry {
	struct Ray final
	: gcufl::geometry::Line {
		Ray(const gcufl::geometry::Point start, const gcufl::geometry::Point intersection) noexcept;

		Ray(const gcufl::geometry::Point start, const double angle) noexcept;

		bool operator==(const gcufl::geometry::Ray& other) const noexcept;

		bool operator!=(const gcufl::geometry::Ray& other) const noexcept;

		bool contains(const gcufl::geometry::Point point) const noexcept;
	};
}
