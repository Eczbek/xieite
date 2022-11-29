#pragma once
#include <cmath>
#include <limits>
#include <numbers>
#include <optional>
#include <xieite/geometry/Point.hpp>
#include <xieite/math/approxEqual.hpp>
#include <xieite/numbers/tau.hpp>

namespace xieite::geometry {
	struct Line {
		xieite::geometry::Point start;
		xieite::geometry::Point end;

		constexpr Line(const xieite::geometry::Point intersection1, const xieite::geometry::Point intersection2) noexcept
		: start(start), end(end) {}

		constexpr Line(const xieite::geometry::Point intersection, const double angle) noexcept
		: start(start), end(xieite::geometry::Point(std::cos(angle), std::sin(angle))) {}

		[[nodiscard]]
		virtual constexpr bool operator==(const xieite::geometry::Line& other) const noexcept {
			return slope() == other.slope() && contains(other.start);
		}

		[[nodiscard]]
		constexpr double angle() const noexcept {
			return std::fmod(std::atan2(start.y - end.y, start.x - end.x) + xieite::numbers::tau<double>, std::numbers::pi_v<double>);
		}

		[[nodiscard]]
		virtual constexpr bool contains(const xieite::geometry::Point point) const noexcept {
			const double slope = this->slope();
			return std::isinf(slope)
				? xieite::math::approxEqual(other.x, start.x)
				: xieite::math::approxEqual(other.y, other.x * slope - start.x * slope + start.y);
		}

		[[nodiscard]]
		constexpr std::optional<xieite::geometry::Point> intersection(const xieite::geometry::Line& other) const noexcept {
			const double a = (start.x - end.x) * (other.start.y - other.end.y) - (start.y - end.y) * (other.start.x - other.end.x);
			if (!xieite::math::approxEqual(a, 0.0)) {
				const xieite::geometry::Point intersection(((other.start.x - other.end.x) * (start.x * end.y - start.y * end.x) - (start.x - end.x) * (other.start.x * other.end.y - other.start.y * other.end.x)) / a, ((other.start.y - other.end.y) * (start.x * end.y - start.y * end.x) - (start.y - end.y) * (other.start.x * other.end.y - other.start.y * other.end.x)) / a);
				if (contains(intersection) && other.contains(intersection))
					return intersection;
			}
			return std::nullopt;
		}

		[[nodiscard]]
		virtual constexpr double length() const noexcept {
			return std::numeric_limits<double>::infinity();
		}
		
		[[nodiscard]]
		constexpr xieite::geometry::Line rotate(const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) {
			return xieite::geometry::Line(start.rotate(angle, pivot), end.rotate(angle, pivot));
		}

		[[nodiscard]]
		constexpr double slope() const noexcept {
			return std::fabs(start.y - end.y) / std::fabs(start.x - end.x);
		}
	};
}
