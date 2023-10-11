#ifndef XIEITE_HEADER_TRAITS_HASHER
#	define XIEITE_HEADER_TRAITS_HASHER

#	include <type_traits>
#	include "../concepts/hasher.hpp"

namespace xieite::traits {
	template<typename Type, typename Argument>
	struct Hasher
	: std::bool_constant<xieite::concepts::Hasher<Type, Argument>> {};
}

#endif
