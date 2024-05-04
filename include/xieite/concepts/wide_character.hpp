#ifndef XIEITE_HEADER_CONCEPTS_WIDE_CHARACTER
#	define XIEITE_HEADER_CONCEPTS_WIDE_CHARACTER

#	include <type_traits>
#	include "../concepts/same_as_any.hpp"

namespace xieite::concepts {
	template<typename Type_>
	concept WideCharacter = xieite::concepts::SameAsAny<std::remove_cv_t<Type_>, wchar_t, char16_t, char32_t>;
}

#endif
