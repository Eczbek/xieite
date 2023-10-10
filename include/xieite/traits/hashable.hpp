#ifndef XIEITE_HEADER__TRAITS___HASHABLE
#	define XIEITE_HEADER__TRAITS___HASHABLE

#	include <type_traits>
#	include "../concepts/hashable.hpp"

namespace xieite::traits {
	template<typename Type>
	struct Hashable
	: std::bool_constant<xieite::concepts::Hashable<Type>> {};
}

#endif
