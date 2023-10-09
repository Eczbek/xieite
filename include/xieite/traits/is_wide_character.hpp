#ifndef XIEITE_HEADER__TRAITS__IS_WIDE_CHARACTER
#	define XIEITE_HEADER__TRAITS__IS_WIDE_CHARACTER

#	include <type_traits>
#	include "../concepts/wide_character.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsWideCharacter
	: std::bool_constant<xieite::concepts::WideCharacter<Type>> {};
}

#endif
