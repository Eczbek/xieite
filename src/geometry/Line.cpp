
#include <cmath>
#include <gcufl/geometry/Line.hpp>
#include <gcufl/geometry/Point.hpp>
#include <gcufl/math/approxEqual.hpp>
#include <gcufl/numbers/tau.hpp>
#include <limits>
#include <numbers>
#include <optional>


gcufl::geometry::Line::Line(const gcufl::geometry::Point start, const gcufl::geometry::Point end) noexcept
: start(start), end(end) {}

gcufl::geometry::Line::Line(const gcufl::geometry::Point start, const double angle) noexcept
: start(start) {
	end = gcufl::math::approxEqual(std::fmod(angle + std::numbers::pi_v<double> / 2, std::numbers::pi_v<double>), 0.0)
		? gcufl::geometry::Point(start.x, start.y - 1)
		: gcufl::geometry::Point(start.x + 1, start.y + std::tan(angle));
}

bool gcufl::geometry::Line::operator==(const gcufl::geometry::Line& other) const noexcept {
	return slope() == other.slope() && contains(other.start);
}

bool gcufl::geometry::Line::operator!=(const gcufl::geometry::Line& other) const noexcept {
	return !(*this == other);
}

double gcufl::geometry::Line::angle() const noexcept {
	return std::fmod(std::atan2(start.y - end.y, start.x - end.x) + gcufl::numbers::tau<double>, std::numbers::pi_v<double>);
}

bool gcufl::geometry::Line::contains(const gcufl::geometry::Point other) const noexcept {
	const double slope = this->slope();
	return std::isinf(slope)
		? gcufl::math::approxEqual(other.x, start.x)
		: gcufl::math::approxEqual(other.y, other.x * slope - start.x * slope + start.y);
}

std::optional<gcufl::geometry::Point> gcufl::geometry::Line::intersection(const gcufl::geometry::Line& other) const noexcept {
	const double a = (start.x - end.x) * (other.start.y - other.end.y) - (start.y - end.y) * (other.start.x - other.end.x);
	if (!gcufl::math::approxEqual(a, 0.0)) {
		const gcufl::geometry::Point intersection(((other.start.x - other.end.x) * (start.x * end.y - start.y * end.x) - (start.x - end.x) * (other.start.x * other.end.y - other.start.y * other.end.x)) / a, ((other.start.y - other.end.y) * (start.x * end.y - start.y * end.x) - (start.y - end.y) * (other.start.x * other.end.y - other.start.y * other.end.x)) / a);
		if (contains(intersection) && other.contains(intersection))
			return intersection;
	}
	return std::nullopt;
}

double gcufl::geometry::Line::length() const noexcept {
	return std::numeric_limits<double>::infinity();
}

gcufl::geometry::Line gcufl::geometry::Line::rotate(const double angle, const gcufl::geometry::Point pivot) {
	return gcufl::geometry::Line(start.rotate(angle, pivot), end.rotate(angle, pivot));
}

double gcufl::geometry::Line::slope() const noexcept {
	return std::fabs(start.y - end.y) / std::fabs(start.x - end.x);
}
