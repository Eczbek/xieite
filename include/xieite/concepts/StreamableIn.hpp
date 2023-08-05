#ifndef XIEITE_HEADER__CONCEPTS__STREAMABLE_IN
#	define XIEITE_HEADER__CONCEPTS__STREAMABLE_IN

#	include "../traits/IsStreamableIn.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept StreamableIn = xieite::traits::IsStreamableIn<Type>::value;
}

#endif
