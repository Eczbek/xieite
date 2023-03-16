#pragma once
#include <concepts> // std::derived_from
#include <optional> // std::nullopt, std::optional
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/containsPoint.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr std::optional<xieite::geometry::Point> getIntersection(const std::derived_from<xieite::geometry::LineLike> auto& lineLike1, const std::derived_from<xieite::geometry::LineLike> auto& lineLike2) noexcept {
		const double a = (lineLike1.start.x - lineLike1.end.x) * (lineLike2.start.y - lineLike2.end.y) - (lineLike1.start.y - lineLike1.end.y) * (lineLike2.start.x - lineLike2.end.x);
		if (!xieite::math::approximatelyEqual(a, 0.0)) {
			const xieite::geometry::Point intersection(((lineLike2.start.x - lineLike2.end.x) * (lineLike1.start.x * lineLike1.end.y - lineLike1.start.y * lineLike1.end.x) - (lineLike1.start.x - lineLike1.end.x) * (lineLike2.start.x * lineLike2.end.y - lineLike2.start.y * lineLike2.end.x)) / a, ((lineLike2.start.y - lineLike2.end.y) * (lineLike1.start.x * lineLike1.end.y - lineLike1.start.y * lineLike1.end.x) - (lineLike1.start.y - lineLike1.end.y) * (lineLike2.start.x * lineLike2.end.y - lineLike2.start.y * lineLike2.end.x)) / a);
			if (xieite::geometry::containsPoint(lineLike1, intersection) && xieite::geometry::containsPoint(lineLike2, intersection))
				return std::optional(intersection);
		}
		return std::nullopt;
	}
}