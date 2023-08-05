#ifndef XIEITE_HEADER__CONCEPTS__ORDINARY_CHARACTER
#	define XIEITE_HEADER__CONCEPTS__ORDINARY_CHARACTER

#	include "../traits/IsOrdinaryCharacter.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept OrdinaryCharacter = xieite::traits::IsOrdinaryCharacter<Type>::value;
}

#endif
