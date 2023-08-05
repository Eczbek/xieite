#ifndef XIEITE_HEADER__TRAITS__IS_NARROW_CHARACTER
#	define XIEITE_HEADER__TRAITS__IS_NARROW_CHARACTER

#	include <concepts>
#	include <type_traits>
#	include "../concepts/OrdinaryCharacter.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsNarrowCharacter
	: std::bool_constant<xieite::concepts::OrdinaryCharacter<Type> || std::same_as<std::remove_cv_t<Type>, char8_t>> {};
}

#endif
