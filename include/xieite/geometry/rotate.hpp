#pragma once
#include <concepts> // std::derived_from
#include <cmath> // std::cos, std::sin
#include <vector> // std::vector
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/math/tau.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr xieite::geometry::Point rotate(const xieite::geometry::Point point, const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point()) noexcept {
		return xieite::geometry::Point(pivot.x + std::cos(angle) * (point.x - pivot.x) - std::sin(angle) * (point.y - pivot.y), pivot.y + std::cos(angle) * (point.y - pivot.y) + std::sin(angle) * (point.x - pivot.x));
	}

	template<std::derived_from<xieite::geometry::LineLike> LineLike>
	[[nodiscard]]
	constexpr LineLike rotate(const LineLike& lineLike, const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point()) noexcept {
		return LineLike(xieite::geometry::rotate(lineLike.start, angle, pivot), xieite::geometry::rotate(lineLike.end, angle, pivot));
	}

	[[nodiscard]]
	constexpr xieite::geometry::Polygon rotate(const xieite::geometry::Polygon& polygon, const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point()) noexcept {
		std::vector<xieite::geometry::Point> rotatedPoints;
		for (const xieite::geometry::Point point : polygon.points)
			rotatedPoints.push_back(xieite::geometry::rotate(point, angle, pivot));
		return xieite::geometry::Polygon(rotatedPoints);
	}

	[[nodiscard]]
	constexpr xieite::geometry::Ellipse rotate(const xieite::geometry::Ellipse& ellipse, const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point()) noexcept {
		return xieite::geometry::Ellipse(xieite::geometry::rotate(ellipse.center, angle, pivot), ellipse.radii, std::fmod(ellipse.rotation + angle, xieite::math::tau<double>));
	}

	[[nodiscard]]
	constexpr xieite::geometry::Circle rotate(const xieite::geometry::Circle& circle, const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point()) noexcept {
		return xieite::geometry::Circle(xieite::geometry::rotate(circle.center, angle, pivot), circle.radius);
	}
}
