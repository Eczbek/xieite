#pragma once

#include <xieite/concepts/SameAsOneOf.hpp>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Ray.hpp>
#include <xieite/geometry/Segment.hpp>

namespace xieite::concepts {
	template<typename Any>
	concept LinearShape = xieite::concepts::SameAsOneOf<Any, xieite::geometry::Line, xieite::geometry::Ray, xieite::geometry::Segment>;
}
