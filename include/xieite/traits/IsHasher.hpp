#ifndef XIEITE_HEADER__TRAITS__IS_HASHER
#	define XIEITE_HEADER__TRAITS__IS_HASHER

#	include <type_traits>
#	include "../concepts/Hasher.hpp"

namespace xieite::traits {
	template<typename Type, typename Argument>
	struct IsHasher
	: std::bool_constant<xieite::concepts::Hasher<Type, Argument>> {};
}

#endif
