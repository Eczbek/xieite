#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CHAR
#	define DETAIL_XTE_HEADER_TRAIT_IS_CHAR
#
#	include "../trait/is_same_any_ignore_cv.hpp"

namespace xte {
	template<typename T>
	concept is_char = xte::is_same_any_ignore_cv<T, char, wchar_t, char8_t, char16_t, char32_t>;
}

#endif
