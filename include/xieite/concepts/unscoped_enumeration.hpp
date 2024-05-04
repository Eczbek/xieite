#ifndef XIEITE_HEADER_CONCEPTS_UNSCOPED_ENUMERATION
#	define XIEITE_HEADER_CONCEPTS_UNSCOPED_ENUMERATION

#	include <concepts>
#	include <type_traits>

namespace xieite::concepts {
	template<typename Type_>
	concept UnscopedEnumeration = std::is_enum_v<std::remove_cv_t<Type_>> && std::convertible_to<std::remove_cv_t<Type_>, std::underlying_type_t<Type_>>;
}

#endif
