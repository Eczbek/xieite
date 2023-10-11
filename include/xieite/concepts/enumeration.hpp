#ifndef XIEITE_HEADER_CONCEPTS_ENUMERATION
#	define XIEITE_HEADER_CONCEPTS_ENUMERATION

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept Enumeration = std::is_enum_v<Type>;
}

#endif
