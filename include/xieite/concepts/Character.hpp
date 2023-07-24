#ifndef XIEITE_HEADER_CONCEPTS_CHARACTER
#	define XIEITE_HEADER_CONCEPTS_CHARACTER

#	include <type_traits>
#	include <xieite/concepts/SameAs.hpp>
#	include <xieite/concepts/WideCharacter.hpp>

namespace xieite::concepts {
	template<typename Any>
	concept Character = xieite::concepts::WideCharacter<Any> || xieite::concepts::SameAs<std::remove_cv_t<Any>, char, char8_t>;
}

#endif
