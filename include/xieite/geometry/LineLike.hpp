#pragma once
#include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	struct LineLike {
		xieite::geometry::Point start;
		xieite::geometry::Point end;

		constexpr LineLike(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}
	};
}
