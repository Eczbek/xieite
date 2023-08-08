#ifndef XIEITE_HEADER__TRAITS__IS_HASHABLE
#	define XIEITE_HEADER__TRAITS__IS_HASHABLE

#	include <type_traits>
#	include "../concepts/Hashable.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsHashable
	: std::bool_constant<xieite::concepts::Hashable<Type>> {};
}

#endif
