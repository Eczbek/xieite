#ifndef XIEITE_HEADER__TRAITS__IS_LINEAR_SHAPE
#	define XIEITE_HEADER__TRAITS__IS_LINEAR_SHAPE

#	include <type_traits>
#	include "../concepts/SameAsAnyOf.hpp"
#	include "../geometry/Line.hpp"
#	include "../geometry/Ray.hpp"
#	include "../geometry/Segment.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsLinearShape
	: std::bool_constant<xieite::concepts::SameAsAnyOf<Type, xieite::geometry::Line, xieite::geometry::Ray, xieite::geometry::Segment>> {};
}

#endif
