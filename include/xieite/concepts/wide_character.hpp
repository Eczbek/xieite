#ifndef XIEITE_HEADER__CONCEPTS__WIDE_CHARACTER
#	define XIEITE_HEADER__CONCEPTS__WIDE_CHARACTER

#	include "../concepts/same_as_any_of.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept WideCharacter = xieite::concepts::SameAsAnyOf<std::remove_cv_t<Type>, wchar_t, char16_t, char32_t>;
}

#endif
