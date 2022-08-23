#include <limits>
#include <gcufl/alg>
#include <gcufl/geom>
#include <gcufl/math>
#include <gcufl/num>


gcufl::geom::Point::Point(const double x, const double y) noexcept
	: x(x), y(y)
{}

bool gcufl::geom::Point::operator==(const gcufl::geom::Point other) const noexcept {
	return gcufl::math::approxEqual(x, other.x) && gcufl::math::approxEqual(y, other.y);
}

bool gcufl::geom::Point::operator!=(const gcufl::geom::Point other) const noexcept {
	return !operator==(other);
}

gcufl::geom::Point gcufl::geom::Point::rotate(const double angle, const gcufl::geom::Point pivot) const noexcept {
	return gcufl::geom::Point(pivot.x + std::cos(angle) * (x - pivot.x) - std::sin(angle) * (y - pivot.y), pivot.y + std::cos(angle) * (y - pivot.y) + std::sin(angle) * (x - pivot.x));
}

gcufl::geom::Line::Line(const gcufl::geom::Point start, const gcufl::geom::Point end) noexcept
	: start(start), end(end)
{}

gcufl::geom::Line::Line(const gcufl::geom::Point start, const double angle) noexcept
	: start(start)
{
	end = gcufl::math::approxEqual(std::fmod(angle + std::numbers::pi / 2, std::numbers::pi), 0.0)
		? gcufl::geom::Point(start.x, start.y - 1)
		: gcufl::geom::Point(start.x + 1, start.y + std::tan(angle));
}

bool gcufl::geom::Line::operator==(const gcufl::geom::Line& other) const noexcept {
	return slope() == other.slope() && contains(other.start);
}

bool gcufl::geom::Line::operator!=(const gcufl::geom::Line& other) const noexcept {
	return !operator==(other);
}

double gcufl::geom::Line::slope() const noexcept {
	return (start.y - end.y) / (start.x - end.x);
}

double gcufl::geom::Line::interceptX() const noexcept {
	return start.x - slope() * start.y;
}

double gcufl::geom::Line::interceptY() const noexcept {
	return start.y - slope() * start.x;
}

double gcufl::geom::Line::angle() const noexcept {
	return std::fmod(std::atan2(start.y - end.y, start.x - end.x) + gcufl::num::tau, std::numbers::pi);
}

std::optional<gcufl::geom::Point> gcufl::geom::Line::intersection(const gcufl::geom::Line& other) const noexcept {
	const double a = (start.x - end.x) * (other.start.y - other.end.y) - (start.y - end.y) * (other.start.x - other.end.x);
	if (!gcufl::math::approxEqual(a, 0.0)) {
		const gcufl::geom::Point intersection(((other.start.x - other.end.x) * (start.x * end.y - start.y * end.x) - (start.x - end.x) * (other.start.x * other.end.y - other.start.y * other.end.x)) / a, ((other.start.y - other.end.y) * (start.x * end.y - start.y * end.x) - (start.y - end.y) * (other.start.x * other.end.y - other.start.y * other.end.x)) / a);
		if (contains(intersection) && other.contains(intersection))
			return intersection;
	}
	return std::nullopt;
}

double gcufl::geom::Line::length() const noexcept {
	return std::numeric_limits<double>::infinity();
}

bool gcufl::geom::Line::contains(const gcufl::geom::Point other) const noexcept {
	const double slope = this->slope();
	return std::isinf(slope)
		? gcufl::math::approxEqual(other.x, start.x)
		: gcufl::math::approxEqual(other.y, other.x * slope - start.x * slope + start.y);
}

gcufl::geom::Line gcufl::geom::Line::rotate(const double angle, const gcufl::geom::Point pivot) {
	return gcufl::geom::Line(start.rotate(angle, pivot), end.rotate(angle, pivot));
}

gcufl::geom::Ray::Ray(const gcufl::geom::Point start, const gcufl::geom::Point end) noexcept
	: gcufl::geom::Line(start, end)
{}

gcufl::geom::Ray::Ray(const gcufl::geom::Point start, const double angle) noexcept
	: gcufl::geom::Line(start, angle)
{}

bool gcufl::geom::Ray::operator==(const gcufl::geom::Ray& other) const noexcept {
	return start == other.start && contains(other.end);
}

bool gcufl::geom::Ray::operator!=(const gcufl::geom::Ray& other) const noexcept {
	return !operator==(other);
}

double gcufl::geom::Ray::length() const noexcept {
	return std::numeric_limits<double>::infinity();
}

bool gcufl::geom::Ray::contains(const gcufl::geom::Point other) const noexcept {
	const double slope = this->slope();
	return (std::isinf(slope)
		? gcufl::math::approxEqual(other.x, start.x)
			&& slope < std::numeric_limits<double>::lowest()
				? other.y >= start.y
				: other.y <= start.y
		: gcufl::math::approxEqual(other.y, other.x * slope - start.x * slope + start.y))
			&& (start.x <= end.x
				? other.x >= start.x
				: other.x <= start.x)
			&& (start.y <= end.y
				? other.y >= start.y
				: other.y <= start.y);
}

gcufl::geom::Segment::Segment(const gcufl::geom::Point start, const gcufl::geom::Point end) noexcept
	: gcufl::geom::Line(start, end)
{}

bool gcufl::geom::Segment::operator==(const gcufl::geom::Segment& other) const noexcept {
	return start == other.start && end == other.end || start == other.end && end == other.start;
}

bool gcufl::geom::Segment::operator!=(const gcufl::geom::Segment& other) const noexcept {
	return !operator==(other);
}

double gcufl::geom::Segment::length() const noexcept {
	return std::hypot(start.x - end.x, start.y - end.y);
}

bool gcufl::geom::Segment::contains(const gcufl::geom::Point other) const noexcept {
	const double slope = this->slope();
	return (std::isinf(slope)
		? gcufl::math::approxEqual(other.x, start.x)
			&& (other.y >= start.y && other.y <= end.y || other.y <= start.y && other.y >= end.y)
		: gcufl::math::approxEqual(other.y, other.x * slope - start.x * slope + start.y))
			&& (start.x < end.x
				? other.x >= start.x && other.x <= end.x
				: other.x <= start.x && other.x >= end.x)
			&& (start.y < end.y
				? other.y >= start.y && other.y <= end.y
				: other.y <= start.y && other.y >= end.y);
}

gcufl::geom::Polygon::Polygon(const std::vector<gcufl::geom::Point>& points) noexcept
	: points(points)
{}

bool gcufl::geom::Polygon::operator==(const gcufl::geom::Polygon& other) const noexcept {
	return gcufl::alg::rotatedMatch(points.begin(), points.end(), other.points.begin(), other.points.end())
		|| gcufl::alg::rotatedMatch(points.rbegin(), points.rend(), other.points.begin(), other.points.end());
}

bool gcufl::geom::Polygon::operator!=(const gcufl::geom::Polygon& other) const noexcept {
	return !operator==(other);
}

double gcufl::geom::Polygon::area() const noexcept {
	double area = 0;
	for (const gcufl::geom::Segment& side: sides())
		area += side.start.x * side.end.y - side.start.y * side.start.x;
	return area / 2;
}

double gcufl::geom::Polygon::perimeter() const noexcept {
	double perimeter = 0;
	for (const gcufl::geom::Segment& side: sides())
		perimeter += side.length();
	return perimeter;
}

std::vector<gcufl::geom::Segment> gcufl::geom::Polygon::sides() const noexcept {
	std::vector<gcufl::geom::Segment> sides;
	for (std::size_t i = 0; i < points.size(); ++i)
		sides.push_back(gcufl::geom::Segment(points[i], points[(i + 1) % points.size()]));
	return sides;
}

bool gcufl::geom::Polygon::contains(const gcufl::geom::Point point) const noexcept {
	std::size_t intersections = 0;
	gcufl::geom::Ray ray(point, 0);
	for (const gcufl::geom::Segment& side: sides())
		intersections += ray.intersection(side).has_value();
	return intersections % 2;
}

gcufl::geom::Polygon gcufl::geom::Polygon::rotate(const double angle, const gcufl::geom::Point pivot) const noexcept {
	std::vector<gcufl::geom::Point> rotatedPoints = points;
	for (std::size_t i = 0; i < points.size(); ++i)
		rotatedPoints[i] = points[i].rotate(angle, pivot);
	return gcufl::geom::Polygon(rotatedPoints);
}

gcufl::geom::Ellipse::Ellipse(const gcufl::geom::Point center, const gcufl::geom::Point radius, const double rotation) noexcept
	: center(center), radius(radius), rotation(rotation)
{}

bool gcufl::geom::Ellipse::operator==(const gcufl::geom::Ellipse& other) const noexcept {
	return center == other.center && radius == other.radius && gcufl::math::approxEqual(std::fmod(rotation, std::numbers::pi), std::fmod(other.rotation, std::numbers::pi));
}

bool gcufl::geom::Ellipse::operator!=(const gcufl::geom::Ellipse& other) const noexcept {
	return !operator==(other);
}

double gcufl::geom::Ellipse::area() const noexcept {
	return std::numbers::pi * radius.x * radius.y;
}

double gcufl::geom::Ellipse::perimiter() const noexcept {
	return std::numbers::pi * std::sqrt(2 * (radius.x * radius.x + radius.y * radius.y));
}

bool gcufl::geom::Ellipse::contains(const gcufl::geom::Point point) const noexcept {
	const double a = std::cos(rotation) * (point.x - center.x) + std::sin(rotation) * (point.y - center.y);
	const double b = std::sin(rotation) * (point.x - center.x) - std::cos(rotation) * (point.y - center.y);
	return a * a / radius.x / radius.x + b * b / radius.y / radius.y <= 1;
}

std::vector<gcufl::geom::Point> gcufl::geom::Ellipse::intersections(const gcufl::geom::Line& line) const noexcept {
	std::vector<gcufl::geom::Point> intersections;
	const double a = radius.y * radius.y * line.end.x * line.end.x + radius.x * radius.x * line.end.y * line.end.y;
	const double b = radius.y * radius.y * line.start.x * line.end.x * 2 + radius.x * radius.x * line.start.y * line.end.y * 2;
	const double c = radius.y * radius.y * line.start.x * line.start.x + radius.x * radius.x * line.start.y * line.start.y - radius.x * radius.x * radius.y * radius.y;
	const double d = std::sqrt(b * b - 4 * a * c) / 2 / a;
	const double e = b * b - 4 * a * c;
	const bool f = gcufl::math::approxEqual(e, 0.0);
	if (e > 0 || f) {
		const gcufl::geom::Point g(center.x + line.start.x + (d - b) * (line.end.x - line.start.x), center.y + line.start.y + (d + b) * (line.end.y - line.start.y));
		if (line.contains(g))
			intersections.push_back(g);
		if (e > 0 && !f) {
			const gcufl::geom::Point h(center.x - line.start.x - (d - b) * (line.end.x - line.start.x), center.y - line.start.y - (d + b) * (line.end.y - line.start.y));
			if (line.contains(h))
				intersections.push_back(h);
		}
	}
	return intersections;
}

std::vector<gcufl::geom::Point> gcufl::geom::Ellipse::intersections(const gcufl::geom::Ellipse& other) const noexcept {
	return {}; // TODO
}

gcufl::geom::Ellipse gcufl::geom::Ellipse::rotate(const double angle, const gcufl::geom::Point pivot) const noexcept {
	return gcufl::geom::Ellipse(center.rotate(angle, pivot), radius, std::fmod(rotation + angle, gcufl::num::tau));
}

gcufl::geom::Polygon gcufl::geom::Ellipse::boundingBox() const noexcept {
	const double a = std::sqrt(radius.x * radius.x * std::cos(rotation) * std::cos(rotation) + radius.y * radius.y * std::cos(rotation + std::numbers::pi / 2) * std::cos(rotation + std::numbers::pi / 2));
	const double b = std::sqrt(radius.x * radius.x * std::sin(rotation) * std::sin(rotation) + radius.y * radius.y * std::sin(rotation + std::numbers::pi / 2) * std::sin(rotation + std::numbers::pi / 2));
	return gcufl::geom::Polygon(std::vector<gcufl::geom::Point> {
		gcufl::geom::Point(center.x - a, center.y - b),
		gcufl::geom::Point(center.x + a, center.y - b),
		gcufl::geom::Point(center.x + a, center.y + b),
		gcufl::geom::Point(center.x - a, center.y + b)
	});
}

gcufl::geom::Circle::Circle(const gcufl::geom::Point center, const double radius) noexcept
	: gcufl::geom::Ellipse(center, gcufl::geom::Point(radius, radius))
{}

bool gcufl::geom::Circle::operator==(const gcufl::geom::Circle& other) const noexcept {
	return center == other.center && gcufl::math::approxEqual(radius.x, other.radius.x);
}

bool gcufl::geom::Circle::operator!=(const gcufl::geom::Circle& other) const noexcept {
	return !operator==(other);
}

bool gcufl::geom::Circle::contains(const gcufl::geom::Point point) const noexcept {
	return std::hypot(point.x - center.x, point.y - center.y) <= radius.x;
}

gcufl::geom::Circle gcufl::geom::Circle::rotate(const double angle, const gcufl::geom::Point pivot) const noexcept {
	return gcufl::geom::Circle(center.rotate(angle, pivot), radius.x);
}
