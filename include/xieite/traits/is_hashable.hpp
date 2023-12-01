#ifndef XIEITE_HEADER_TRAITS_IS_HASHABLE
#	define XIEITE_HEADER_TRAITS_IS_HASHABLE

#	include <type_traits>
#	include "../concepts/hashable.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsHashable
	: std::bool_constant<xieite::concepts::Hashable<Type>> {};
}

#endif
