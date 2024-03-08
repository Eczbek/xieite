#ifndef XIEITE_HEADER_CONCEPTS_STRING
#	define XIEITE_HEADER_CONCEPTS_STRING

#	include <string>
#	include "../concepts/specialization_of_any.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept String = xieite::concepts::SpecializationOfAny<Type, std::basic_string, std::pmr::basic_string>;
}

#endif
