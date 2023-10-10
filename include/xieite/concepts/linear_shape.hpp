#pragma once

#include "../concepts/same_as_any.hpp"
#include "../geometry/line.hpp"
#include "../geometry/ray.hpp"
#include "../geometry/segment.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept LinearShape = xieite::concepts::SameAsAny<Type, xieite::geometry::Line, xieite::geometry::Ray, xieite::geometry::Segment>;
}
