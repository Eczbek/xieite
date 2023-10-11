#ifndef XIEITE_HEADER_CONCEPTS_ORDINARY_CHARACTER
#	define XIEITE_HEADER_CONCEPTS_ORDINARY_CHARACTER

#	include <type_traits>
#	include "../concepts/same_as_any.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept OrdinaryCharacter = xieite::concepts::SameAsAny<std::remove_cv_t<Type>, char, signed char, unsigned char>;
}

#endif
