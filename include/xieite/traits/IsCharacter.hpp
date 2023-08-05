#ifndef XIEITE_HEADER__TRAITS__IS_CHARACTER
#	define XIEITE_HEADER__TRAITS__IS_CHARACTER

#	include <type_traits>
#	include "../concepts/SameAsAnyOf.hpp"
#	include "../concepts/WideCharacter.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsCharacter
	: std::bool_constant<xieite::concepts::WideCharacter<Type> || xieite::concepts::SameAsAnyOf<std::remove_cv_t<Type>, char, char8_t>> {};
}

#endif
