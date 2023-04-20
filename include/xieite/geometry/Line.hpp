#pragma once

#include <cmath>
#include <xieite/concepts/LinearShape.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getSlope.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	struct Line {
		xieite::geometry::Point start;
		xieite::geometry::Point end;

		constexpr Line(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}

		constexpr Line(const xieite::geometry::Point start, const double angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Line& line) const noexcept {
			const double slope = xieite::geometry::getSlope(*this);
			return (std::isinf(slope) ? xieite::math::approximatelyEqual(this->start.x, line.start.x) : xieite::math::approximatelyEqual(line.start.x * slope - this->start.x * slope + this->start.y, line.start.y)) && xieite::math::approximatelyEqual(slope, xieite::geometry::getSlope(line));
		}

		[[nodiscard]]
		constexpr bool operator==(const xieite::concepts::LinearShape auto&) const noexcept {
			return false;
		}
	};
}
