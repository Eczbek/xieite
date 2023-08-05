#ifndef XIEITE_HEADER__CONCEPTS__STREAMABLE_OUT
#	define XIEITE_HEADER__CONCEPTS__STREAMABLE_OUT

#	include "../traits/IsStreamableOut.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept StreamableOut = xieite::traits::IsStreamableOut<Type>::value;
}

#endif
