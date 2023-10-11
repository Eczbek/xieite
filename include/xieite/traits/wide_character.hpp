#ifndef XIEITE_HEADER_TRAITS_WIDE_CHARACTER
#	define XIEITE_HEADER_TRAITS_WIDE_CHARACTER

#	include <type_traits>
#	include "../concepts/wide_character.hpp"

namespace xieite::traits {
	template<typename Type>
	struct WideCharacter
	: std::bool_constant<xieite::concepts::WideCharacter<Type>> {};
}

#endif
