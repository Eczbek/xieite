#pragma once

#include <cmath>
#include <gcufl/geometry/Point.hpp>
#include <gcufl/math/approxEqual.hpp>
#include <gcufl/numbers/tau.hpp>
#include <limits>
#include <numbers>
#include <optional>


namespace gcufl::geometry {
	struct Line {
		gcufl::geometry::Point start;
		gcufl::geometry::Point end;

		constexpr Line(const gcufl::geometry::Point intersection1, const gcufl::geometry::Point intersection2) noexcept
		: start(start), end(end) {}

		constexpr Line(const gcufl::geometry::Point intersection, const double angle) noexcept
		: start(start), end(gcufl::geometry::Point(std::cos(angle), std::sin(angle))) {}

		virtual constexpr bool operator==(const gcufl::geometry::Line& other) const noexcept {
			return slope() == other.slope() && contains(other.start);
		}

		virtual constexpr bool operator!=(const gcufl::geometry::Line& other) const noexcept {
			return !(*this == other);
		}

		constexpr double angle() const noexcept {
			return std::fmod(std::atan2(start.y - end.y, start.x - end.x) + gcufl::numbers::tau<double>, std::numbers::pi_v<double>);
		}

		virtual constexpr bool contains(const gcufl::geometry::Point point) const noexcept {
			const double slope = this->slope();
			return std::isinf(slope)
				? gcufl::math::approxEqual(other.x, start.x)
				: gcufl::math::approxEqual(other.y, other.x * slope - start.x * slope + start.y);
		}

		constexpr std::optional<gcufl::geometry::Point> intersection(const gcufl::geometry::Line& other) const noexcept {
			const double a = (start.x - end.x) * (other.start.y - other.end.y) - (start.y - end.y) * (other.start.x - other.end.x);
			if (!gcufl::math::approxEqual(a, 0.0)) {
				const gcufl::geometry::Point intersection(((other.start.x - other.end.x) * (start.x * end.y - start.y * end.x) - (start.x - end.x) * (other.start.x * other.end.y - other.start.y * other.end.x)) / a, ((other.start.y - other.end.y) * (start.x * end.y - start.y * end.x) - (start.y - end.y) * (other.start.x * other.end.y - other.start.y * other.end.x)) / a);
				if (contains(intersection) && other.contains(intersection))
					return intersection;
			}
			return std::nullopt;
		}

		virtual constexpr double length() const noexcept {
			return std::numeric_limits<double>::infinity();
		}
		
		constexpr gcufl::geometry::Line rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) {
			return gcufl::geometry::Line(start.rotate(angle, pivot), end.rotate(angle, pivot));
		}

		constexpr double slope() const noexcept {
			return std::fabs(start.y - end.y) / std::fabs(start.x - end.x);
		}
	};
}
