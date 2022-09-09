#pragma once


namespace gcufl::geometry {
	struct Point final {
		double x;
		double y;

		Point(const double x = 0, const double y = 0) noexcept;

		bool operator==(const gcufl::geometry::Point other) const noexcept;

		bool operator!=(const gcufl::geometry::Point other) const noexcept;

		gcufl::geometry::Point rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept;
	};
}
