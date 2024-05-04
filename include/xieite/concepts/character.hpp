#ifndef XIEITE_HEADER_CONCEPTS_CHARACTER
#	define XIEITE_HEADER_CONCEPTS_CHARACTER

#	include <type_traits>
#	include "../concepts/same_as_any.hpp"
#	include "../concepts/wide_character.hpp"

namespace xieite::concepts {
	template<typename Type_>
	concept Character = xieite::concepts::WideCharacter<Type_> || xieite::concepts::SameAsAny<std::remove_cv_t<Type_>, char, char8_t>;
}

#endif
