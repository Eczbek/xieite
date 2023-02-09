#pragma once
#include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	struct AbstractLine {
		xieite::geometry::Point start;
		xieite::geometry::Point end;

		constexpr AbstractLine(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}
	};
}
