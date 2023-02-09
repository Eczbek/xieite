#pragma once
#include <concepts> // std::derived_from
#include <optional> // std::nullopt, std::optional
#include <xieite/geometry/AbstractLine.hpp>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/containsPoint.hpp>

namespace xieite::geometry {
	template<std::derived_from<xieite::geometry::AbstractLine> LineLike1, std::derived_from<xieite::geometry::AbstractLine> LineLike2>
	[[nodiscard]]
	constexpr std::optional<xieite::geometry::Point> getIntersection(const LineLike1& lineLike1, const LineLike2& lineLike2) noexcept {
		const long double a = (lineLike1.start.x - lineLike1.end.x) * (lineLike2.start.y - lineLike2.end.y) - (lineLike1.start.y - lineLike1.end.y) * (lineLike2.start.x - lineLike2.end.x);
		if (!xieite::math::approximatelyEqual(a, static_cast<long double>(0))) {
			const xieite::geometry::Point intersection(((lineLike2.start.x - lineLike2.end.x) * (lineLike1.start.x * lineLike1.end.y - lineLike1.start.y * lineLike1.end.x) - (lineLike1.start.x - lineLike1.end.x) * (lineLike2.start.x * lineLike2.end.y - lineLike2.start.y * lineLike2.end.x)) / a, ((lineLike2.start.y - lineLike2.end.y) * (lineLike1.start.x * lineLike1.end.y - lineLike1.start.y * lineLike1.end.x) - (lineLike1.start.y - lineLike1.end.y) * (lineLike2.start.x * lineLike2.end.y - lineLike2.start.y * lineLike2.end.x)) / a);
			if (xieite::geometry::containsPoint(lineLike1, intersection) && xieite::geometry::containsPoint(lineLike2, intersection))
				return intersection;
		}
		return std::nullopt;
	}
}