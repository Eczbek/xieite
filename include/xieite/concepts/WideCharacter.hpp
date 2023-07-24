#ifndef XIEITE_HEADER_CONCEPTS_WIDECHARACTER
#	define XIEITE_HEADER_CONCEPTS_WIDECHARACTER

#	include <type_traits>
#	include <xieite/concepts/SameAs.hpp>

namespace xieite::concepts {
	template<typename Any>
	concept WideCharacter = xieite::concepts::SameAs<std::remove_cv_t<Any>, wchar_t, char16_t, char32_t>;
}

#endif
