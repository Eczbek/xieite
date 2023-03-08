#pragma once
#include <concepts> // std::derived_from
#include <optional> // std::optional
#include <vector> // std::vector
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getIntersection.hpp>
#include <xieite/geometry/getSides.hpp>

namespace xieite::geometry {
	template<std::derived_from<xieite::geometry::LineLike> L>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const L& lineLike, const xieite::geometry::Polygon& polygon) noexcept {
		std::vector<xieite::geometry::Point> intersections;
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			const std::optional<xieite::geometry::Point> intersection = xieite::geometry::getIntersection(lineLike, side);
			if (intersection.has_value())
				intersections.push_back(intersection.value());
		}
		return intersections;
	}

	template<std::derived_from<xieite::geometry::LineLike> L>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const L& lineLike) noexcept {
		return xieite::geometry::getIntersections(polygon, lineLike);
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept {
		std::vector<xieite::geometry::Point> intersections;
		for (const xieite::geometry::Segment& side1 : xieite::geometry::getSides(polygon1))
			for (const xieite::geometry::Segment& side2 : xieite::geometry::getSides(polygon2)) {
				const std::optional<xieite::geometry::Point> intersection = xieite::geometry::getIntersection(side1, side2);
				if (intersection.has_value())
					intersections.push_back(intersection.value());
			}
		return intersections;
	}
}
