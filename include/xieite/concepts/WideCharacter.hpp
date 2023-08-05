#ifndef XIEITE_HEADER__CONCEPTS__WIDE_CHARACTER
#	define XIEITE_HEADER__CONCEPTS__WIDE_CHARACTER

#	include "../traits/IsWideCharacter.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept WideCharacter = xieite::traits::IsWideCharacter<Type>::value;
}

#endif
