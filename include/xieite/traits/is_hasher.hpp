#ifndef XIEITE_HEADER_TRAITS_IS_HASHER
#	define XIEITE_HEADER_TRAITS_IS_HASHER

#	include <type_traits>
#	include "../concepts/hasher.hpp"

namespace xieite::traits {
	template<typename Type_, typename Argument_>
	struct IsHasher
	: std::bool_constant<xieite::concepts::Hasher<Type_, Argument_>> {};
}

#endif
