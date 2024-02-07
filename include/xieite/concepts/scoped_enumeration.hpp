#ifndef XIEITE_HEADER_CONCEPTS_SCOPED_ENUMERATION
#	define XIEITE_HEADER_CONCEPTS_SCOPED_ENUMERATION

#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept ScopedEnumeration = std::is_scoped_enum_v<Type>;
}

#endif
