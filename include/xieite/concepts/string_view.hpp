#ifndef XIEITE_HEADER_CONCEPTS_STRING_VIEW
#	define XIEITE_HEADER_CONCEPTS_STRING_VIEW

#	include <string_view>
#	include "../concepts/specialization_of.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept StringView = xieite::concepts::SpecializationOf<Type, std::basic_string_view>;
}

#endif
