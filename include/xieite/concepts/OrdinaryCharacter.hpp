#ifndef XIEITE_HEADER_CONCEPTS_ORDINARYCHARACTER
#	define XIEITE_HEADER_CONCEPTS_ORDINARYCHARACTER

#	include <type_traits>
#	include "../concepts/SameAs.hpp"

namespace xieite::concepts {
	template<typename Any>
	concept OrdinaryCharacter = xieite::concepts::SameAs<std::remove_cv_t<Any>, char, signed char, unsigned char>;
}

#endif
