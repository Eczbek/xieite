#ifndef XIEITE_HEADER_CONCEPTS_UNSCOPED_ENUMERATION
#	define XIEITE_HEADER_CONCEPTS_UNSCOPED_ENUMERATION

#	include <concepts>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type>
	concept UnscopedEnumeration = std::is_enum_v<Type> && std::convertible_to<Type, std::underlying_type_t<Type>>;
}

#endif
