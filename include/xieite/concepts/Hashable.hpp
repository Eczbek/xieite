#ifndef XIEITE_HEADER__CONCEPTS__HASHABLE
#	define XIEITE_HEADER__CONCEPTS__HASHABLE

#	include "../traits/IsHashable.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Hashable = xieite::traits::IsHashable<Type>::value;
}

#endif
