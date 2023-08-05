#ifndef XIEITE_HEADER__CONCEPTS__LINEAR_SHAPE
#	define XIEITE_HEADER__CONCEPTS__LINEAR_SHAPE

#	include "../traits/IsLinearShape.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept LinearShape = xieite::traits::IsLinearShape<Type>::value;
}

#endif
