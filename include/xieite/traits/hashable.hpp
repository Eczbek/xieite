#ifndef XIEITE_HEADER_TRAITS_HASHABLE
#	define XIEITE_HEADER_TRAITS_HASHABLE

#	include <type_traits>
#	include "../concepts/hashable.hpp"

namespace xieite::traits {
	template<typename Type>
	struct Hashable
	: std::bool_constant<xieite::concepts::Hashable<Type>> {};
}

#endif
