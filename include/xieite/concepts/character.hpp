#ifndef XIEITE_HEADER__CONCEPTS__CHARACTER
#	define XIEITE_HEADER__CONCEPTS__CHARACTER

#	include <type_traits>
#	include "../concepts/same_as_any_of.hpp"
#	include "../concepts/wide_character.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Character = xieite::concepts::WideCharacter<Type> || xieite::concepts::SameAsAnyOf<std::remove_cv_t<Type>, char, char8_t>;
}

#endif
