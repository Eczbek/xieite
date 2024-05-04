#ifndef XIEITE_HEADER_TRAITS_IS_UNSCOPED_ENUMERATION
#	define XIEITE_HEADER_TRAITS_IS_UNSCOPED_ENUMERATION

#	include <type_traits>
#	include "../concepts/unscoped_enumeration.hpp"

namespace xieite::traits {
	template<typename Type_>
	struct IsUnscopedEnumeration
	: std::bool_constant<xieite::concepts::UnscopedEnumeration<Type_>> {};
}

#endif
