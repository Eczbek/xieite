#pragma once

#include <optional>
#include <xieite/concepts/LinearShape.hpp>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/containsPoint.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr std::optional<xieite::geometry::Point> getIntersection(const xieite::concepts::LinearShape auto& linearShape1, const xieite::concepts::LinearShape auto& linearShape2) noexcept {
		const double a = (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.y - linearShape2.end.y) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x - linearShape2.end.x);
		if (!xieite::math::approximatelyEqual(a, 0.0)) {
			const xieite::geometry::Point intersection(((linearShape2.start.x - linearShape2.end.x) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / a, ((linearShape2.start.y - linearShape2.end.y) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / a);
			if (xieite::geometry::containsPoint(linearShape1, intersection) && xieite::geometry::containsPoint(linearShape2, intersection)) {
				return std::optional(intersection);
			}
		}
		return std::nullopt;
	}
}