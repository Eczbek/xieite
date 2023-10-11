#ifndef XIEITE_HEADER_CONCEPTS_WIDE_CHARACTER
#	define XIEITE_HEADER_CONCEPTS_WIDE_CHARACTER

#	include "../concepts/same_as_any.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept WideCharacter = xieite::concepts::SameAsAny<std::remove_cv_t<Type>, wchar_t, char16_t, char32_t>;
}

#endif
