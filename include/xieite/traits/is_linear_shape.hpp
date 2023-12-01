#ifndef XIEITE_HEADER_TRAITS_IS_LINEAR_SHAPE
#	define XIEITE_HEADER_TRAITS_IS_LINEAR_SHAPE

#	include <type_traits>
#	include "../concepts/linear_shape.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsLinearShape
	: std::bool_constant<xieite::concepts::LinearShape<Type>> {};
}

#endif
