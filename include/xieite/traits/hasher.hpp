#ifndef XIEITE_HEADER__TRAITS___HASHER
#	define XIEITE_HEADER__TRAITS___HASHER

#	include <type_traits>
#	include "../concepts/hasher.hpp"

namespace xieite::traits {
	template<typename Type, typename Argument>
	struct Hasher
	: std::bool_constant<xieite::concepts::Hasher<Type, Argument>> {};
}

#endif
