#pragma once
#include <cmath>
#include <numbers>
#include <vector>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/math/approxEqual.hpp>
#include <xieite/math/pi.hpp>
#include <xieite/math/tau.hpp>

namespace xieite::geometry {
	struct Ellipse {
		xieite::geometry::Point center;
		xieite::geometry::Point radius;
		long double rotation;

		constexpr Ellipse(const xieite::geometry::Point center, const xieite::geometry::Point radius, const long double rotation = 0) noexcept
		: center(center), radius(radius), rotation(rotation) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Ellipse& other) const noexcept {
			return center == other.center && radius == other.radius && xieite::math::approxEqual(std::fmod(rotation, xieite::math::pi<long double>), std::fmod(other.rotation, xieite::math::pi<long double>));
		}

		[[nodiscard]]
		virtual constexpr long double area() const noexcept {
			return xieite::math::pi<long double> * radius.x * radius.y;
		}

		[[nodiscard]]
		virtual constexpr xieite::geometry::Polygon boundingBox() const noexcept {
			const long double a = std::sqrt(radius.x * radius.x * std::cos(rotation) * std::cos(rotation) + radius.y * radius.y * std::cos(rotation + xieite::math::pi<long double> / 2) * std::cos(rotation + xieite::math::pi<long double> / 2));
			const long double b = std::sqrt(radius.x * radius.x * std::sin(rotation) * std::sin(rotation) + radius.y * radius.y * std::sin(rotation + xieite::math::pi<long double> / 2) * std::sin(rotation + xieite::math::pi<long double> / 2));
			return xieite::geometry::Polygon(std::vector<xieite::geometry::Point> {
				xieite::geometry::Point(center.x - a, center.y - b),
				xieite::geometry::Point(center.x + a, center.y - b),
				xieite::geometry::Point(center.x + a, center.y + b),
				xieite::geometry::Point(center.x - a, center.y + b)
			});
		}

		[[nodiscard]]
		virtual constexpr bool contains(const xieite::geometry::Point point) const noexcept {
			const long double a = std::cos(rotation) * (point.x - center.x) + std::sin(rotation) * (point.y - center.y);
			const long double b = std::sin(rotation) * (point.x - center.x) - std::cos(rotation) * (point.y - center.y);
			return a * a / radius.x / radius.x + b * b / radius.y / radius.y <= 1;
		}

		[[nodiscard]]
		constexpr std::vector<xieite::geometry::Point> intersections(const xieite::geometry::Line& line) const noexcept {
			std::vector<xieite::geometry::Point> intersections;
			const long double a = radius.y * radius.y * line.end.x * line.end.x + radius.x * radius.x * line.end.y * line.end.y;
			const long double b = radius.y * radius.y * line.start.x * line.end.x * 2 + radius.x * radius.x * line.start.y * line.end.y * 2;
			const long double c = radius.y * radius.y * line.start.x * line.start.x + radius.x * radius.x * line.start.y * line.start.y - radius.x * radius.x * radius.y * radius.y;
			const long double d = std::sqrt(b * b - 4 * a * c) / 2 / a;
			const long double e = b * b - 4 * a * c;
			const bool f = xieite::math::approxEqual(e, static_cast<long double>(0));
			if (e > 0 || f) {
				const xieite::geometry::Point g(center.x + line.start.x + (d - b) * (line.end.x - line.start.x), center.y + line.start.y + (d + b) * (line.end.y - line.start.y));
				if (line.contains(g))
					intersections.push_back(g);
				if (e > 0 && !f) {
					const xieite::geometry::Point h(center.x - line.start.x - (d - b) * (line.end.x - line.start.x), center.y - line.start.y - (d + b) * (line.end.y - line.start.y));
					if (line.contains(h))
						intersections.push_back(h);
				}
			}
			return intersections;
		}

		[[nodiscard]]
		virtual constexpr long double perimeter() const noexcept {
			return xieite::math::pi<long double> * std::sqrt(2 * (radius.x * radius.x + radius.y * radius.y));
		}

		[[nodiscard]]
		constexpr xieite::geometry::Ellipse rotate(const long double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) const noexcept {
			return xieite::geometry::Ellipse(center.rotate(angle, pivot), radius, std::fmod(rotation + angle, xieite::math::tau<long double>));
		}
	};
}
