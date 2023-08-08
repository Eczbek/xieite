#ifndef XIEITE_HEADER__TRAITS__IS_LINEAR_SHAPE
#	define XIEITE_HEADER__TRAITS__IS_LINEAR_SHAPE

#	include <type_traits>
#	include "../concepts/LinearShape.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsLinearShape
	: std::bool_constant<xieite::concepts::LinearShape<Type>> {};
}

#endif
