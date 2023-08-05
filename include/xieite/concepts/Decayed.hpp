#ifndef XIEITE_HEADER__CONCEPTS__DECAYED
#	define XIEITE_HEADER__CONCEPTS__DECAYED

#	include "../traits/IsDecayed.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Decayed = xieite::traits::IsDecayed<Type>::value;
}

#endif
