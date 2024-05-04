#ifndef XIEITE_HEADER_CONCEPTS_NARROW_CHARACTER
#	define XIEITE_HEADER_CONCEPTS_NARROW_CHARACTER

#	include <concepts>
#	include <type_traits>
#	include "../concepts/ordinary_character.hpp"

namespace xieite::concepts {
	template<typename Type_>
	concept NarrowCharacter = xieite::concepts::OrdinaryCharacter<Type_> || std::same_as<std::remove_cv_t<Type_>, char8_t>;
}

#endif
