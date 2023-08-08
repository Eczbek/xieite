#ifndef XIEITE_HEADER__CONCEPTS__CHARACTER
#	define XIEITE_HEADER__CONCEPTS__CHARACTER

#	include <type_traits>
#	include "../concepts/SameAsAnyOf.hpp"
#	include "../concepts/WideCharacter.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Character = xieite::concepts::WideCharacter<Type> || xieite::concepts::SameAsAnyOf<std::remove_cv_t<Type>, char, char8_t>;
}

#endif
