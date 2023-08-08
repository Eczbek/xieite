#ifndef XIEITE_HEADER__CONCEPTS__LINEAR_SHAPE
#	define XIEITE_HEADER__CONCEPTS__LINEAR_SHAPE

#	include "../concepts/SameAsAnyOf.hpp"
#	include "../geometry/Line.hpp"
#	include "../geometry/Ray.hpp"
#	include "../geometry/Segment.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept LinearShape = xieite::concepts::SameAsAnyOf<Type, xieite::geometry::Line, xieite::geometry::Ray, xieite::geometry::Segment>;
}

#endif
