
#include <cmath>
#include <gcufl/geometry/Ellipse.hpp>
#include <gcufl/geometry/Line.hpp>
#include <gcufl/geometry/Point.hpp>
#include <gcufl/geometry/Polygon.hpp>
#include <gcufl/math/approxEqual.hpp>
#include <gcufl/numbers/tau.hpp>
#include <numbers>
#include <vector>


gcufl::geometry::Ellipse::Ellipse(const gcufl::geometry::Point center, const gcufl::geometry::Point radius, const double rotation) noexcept
: center(center), radius(radius), rotation(rotation) {}

bool gcufl::geometry::Ellipse::operator==(const gcufl::geometry::Ellipse& other) const noexcept {
	return center == other.center && radius == other.radius && gcufl::math::approxEqual(std::fmod(rotation, std::numbers::pi_v<double>), std::fmod(other.rotation, std::numbers::pi_v<double>));
}

bool gcufl::geometry::Ellipse::operator!=(const gcufl::geometry::Ellipse& other) const noexcept {
	return !(*this == other);
}

double gcufl::geometry::Ellipse::area() const noexcept {
	return std::numbers::pi_v<double> * radius.x * radius.y;
}

gcufl::geometry::Polygon gcufl::geometry::Ellipse::boundingBox() const noexcept {
	const double a = std::sqrt(radius.x * radius.x * std::cos(rotation) * std::cos(rotation) + radius.y * radius.y * std::cos(rotation + std::numbers::pi_v<double> / 2) * std::cos(rotation + std::numbers::pi_v<double> / 2));
	const double b = std::sqrt(radius.x * radius.x * std::sin(rotation) * std::sin(rotation) + radius.y * radius.y * std::sin(rotation + std::numbers::pi_v<double> / 2) * std::sin(rotation + std::numbers::pi_v<double> / 2));
	return gcufl::geometry::Polygon(std::vector<gcufl::geometry::Point> {
		gcufl::geometry::Point(center.x - a, center.y - b),
		gcufl::geometry::Point(center.x + a, center.y - b),
		gcufl::geometry::Point(center.x + a, center.y + b),
		gcufl::geometry::Point(center.x - a, center.y + b)
	});
}

bool gcufl::geometry::Ellipse::contains(const gcufl::geometry::Point point) const noexcept {
	const double a = std::cos(rotation) * (point.x - center.x) + std::sin(rotation) * (point.y - center.y);
	const double b = std::sin(rotation) * (point.x - center.x) - std::cos(rotation) * (point.y - center.y);
	return a * a / radius.x / radius.x + b * b / radius.y / radius.y <= 1;
}

std::vector<gcufl::geometry::Point> gcufl::geometry::Ellipse::intersections(const gcufl::geometry::Line& line) const noexcept {
	std::vector<gcufl::geometry::Point> intersections;
	const double a = radius.y * radius.y * line.end.x * line.end.x + radius.x * radius.x * line.end.y * line.end.y;
	const double b = radius.y * radius.y * line.start.x * line.end.x * 2 + radius.x * radius.x * line.start.y * line.end.y * 2;
	const double c = radius.y * radius.y * line.start.x * line.start.x + radius.x * radius.x * line.start.y * line.start.y - radius.x * radius.x * radius.y * radius.y;
	const double d = std::sqrt(b * b - 4 * a * c) / 2 / a;
	const double e = b * b - 4 * a * c;
	const bool f = gcufl::math::approxEqual(e, 0.0);
	if (e > 0 || f) {
		const gcufl::geometry::Point g(center.x + line.start.x + (d - b) * (line.end.x - line.start.x), center.y + line.start.y + (d + b) * (line.end.y - line.start.y));
		if (line.contains(g))
			intersections.push_back(g);
		if (e > 0 && !f) {
			const gcufl::geometry::Point h(center.x - line.start.x - (d - b) * (line.end.x - line.start.x), center.y - line.start.y - (d + b) * (line.end.y - line.start.y));
			if (line.contains(h))
				intersections.push_back(h);
		}
	}
	return intersections;
}

double gcufl::geometry::Ellipse::perimeter() const noexcept {
	return std::numbers::pi_v<double> * std::sqrt(2 * (radius.x * radius.x + radius.y * radius.y));
}

gcufl::geometry::Ellipse gcufl::geometry::Ellipse::rotate(const double angle, const gcufl::geometry::Point pivot) const noexcept {
	return gcufl::geometry::Ellipse(center.rotate(angle, pivot), radius, std::fmod(rotation + angle, gcufl::numbers::tau<double>));
}
