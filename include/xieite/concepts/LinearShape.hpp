#ifndef XIEITE_HEADER_CONCEPTS_LINEARSHAPE
#	define XIEITE_HEADER_CONCEPTS_LINEARSHAPE

#	include "../concepts/SameAs.hpp"
#	include "../geometry/Line.hpp"
#	include "../geometry/Ray.hpp"
#	include "../geometry/Segment.hpp"

namespace xieite::concepts {
	template<typename Any>
	concept LinearShape = xieite::concepts::SameAs<Any, xieite::geometry::Line, xieite::geometry::Ray, xieite::geometry::Segment>;
}

#endif
