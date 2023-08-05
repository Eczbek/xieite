#ifndef XIEITE_HEADER__CONCEPTS__CHARACTER
#	define XIEITE_HEADER__CONCEPTS__CHARACTER

#	include "../traits/IsCharacter.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Character = xieite::traits::IsCharacter<Type>::value;
}

#endif
