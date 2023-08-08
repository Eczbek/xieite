#ifndef XIEITE_HEADER__CONCEPTS__NARROW_CHARACTER
#	define XIEITE_HEADER__CONCEPTS__NARROW_CHARACTER

#	include <concepts>
#	include <type_traits>
#	include "../concepts/OrdinaryCharacter.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept NarrowCharacter = xieite::concepts::OrdinaryCharacter<Type> || std::same_as<std::remove_cv_t<Type>, char8_t>;
}

#endif
