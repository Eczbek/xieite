#ifndef XIEITE_HEADER_CONCEPTS_LINEARSHAPE
#	define XIEITE_HEADER_CONCEPTS_LINEARSHAPE

#	include <xieite/concepts/SameAs.hpp>
#	include <xieite/geometry/Line.hpp>
#	include <xieite/geometry/Ray.hpp>
#	include <xieite/geometry/Segment.hpp>

namespace xieite::concepts {
	template<typename Any>
	concept LinearShape = xieite::concepts::SameAs<Any, xieite::geometry::Line, xieite::geometry::Ray, xieite::geometry::Segment>;
}

#endif
