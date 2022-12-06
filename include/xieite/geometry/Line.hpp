#pragma once
#include <cmath>
#include <limits>
#include <numbers>
#include <optional>
#include <xieite/geometry/Point.hpp>
#include <xieite/math/approxEqual.hpp>
#include <xieite/math/pi.hpp>
#include <xieite/math/tau.hpp>

namespace xieite::geometry {
	class Line {
	public:
		xieite::geometry::Point start;
		xieite::geometry::Point end;

		constexpr Line(const xieite::geometry::Point intersection1, const xieite::geometry::Point intersection2) noexcept
		: start(intersection1), end(intersection2) {}

		constexpr Line(const xieite::geometry::Point intersection, const long double angle) noexcept
		: start(intersection), end(xieite::geometry::Point(std::cos(angle), std::sin(angle))) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Line& other) const noexcept {
			return slope() == other.slope() && contains(other.start);
		}

		[[nodiscard]]
		constexpr long double angle() const noexcept {
			return std::fmod(std::atan2(start.y - end.y, start.x - end.x) + xieite::math::tau<long double>, xieite::math::pi<long double>);
		}

		[[nodiscard]]
		virtual constexpr bool contains(const xieite::geometry::Point point) const noexcept {
			const long double slope = this->slope();
			return std::isinf(slope)
				? xieite::math::approxEqual(point.x, start.x)
				: xieite::math::approxEqual(point.y, point.x * slope - start.x * slope + start.y);
		}

		[[nodiscard]]
		constexpr std::optional<xieite::geometry::Point> intersection(const xieite::geometry::Line& other) const noexcept {
			const long double a = (start.x - end.x) * (other.start.y - other.end.y) - (start.y - end.y) * (other.start.x - other.end.x);
			if (!xieite::math::approxEqual(a, static_cast<long double>(0))) {
				const xieite::geometry::Point intersection(((other.start.x - other.end.x) * (start.x * end.y - start.y * end.x) - (start.x - end.x) * (other.start.x * other.end.y - other.start.y * other.end.x)) / a, ((other.start.y - other.end.y) * (start.x * end.y - start.y * end.x) - (start.y - end.y) * (other.start.x * other.end.y - other.start.y * other.end.x)) / a);
				if (contains(intersection) && other.contains(intersection))
					return intersection;
			}
			return std::nullopt;
		}

		[[nodiscard]]
		virtual constexpr long double length() const noexcept {
			return std::numeric_limits<long double>::infinity();
		}
		
		[[nodiscard]]
		constexpr xieite::geometry::Line rotate(const long double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) const noexcept {
			return xieite::geometry::Line(start.rotate(angle, pivot), end.rotate(angle, pivot));
		}

		[[nodiscard]]
		constexpr long double slope() const noexcept {
			return std::fabs(start.y - end.y) / std::fabs(start.x - end.x);
		}
	};
}
