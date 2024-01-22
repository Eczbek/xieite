#ifndef XIEITE_HEADER_CONCEPTS_NARROW_CHARACTER
#	define XIEITE_HEADER_CONCEPTS_NARROW_CHARACTER

#	include <concepts>
#	include <type_traits>
#	include "../concepts/ordinary_character.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept NarrowCharacter = xieite::concepts::OrdinaryCharacter<Type> || std::same_as<std::remove_cv_t<Type>, char8_t>;
	// https://eel.is/c++draft/basic.fundamental#7
}

#endif
