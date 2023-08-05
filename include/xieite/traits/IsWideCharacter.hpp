#ifndef XIEITE_HEADER__TRAITS__IS_WIDE_CHARACTER
#	define XIEITE_HEADER__TRAITS__IS_WIDE_CHARACTER

#	include <type_traits>
#	include "../concepts/SameAsAnyOf.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsWideCharacter
	: std::bool_constant<xieite::concepts::SameAsAnyOf<std::remove_cv_t<Type>, wchar_t, char16_t, char32_t>> {};
}

#endif
