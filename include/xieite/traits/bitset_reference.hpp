#ifndef XIEITE_HEADER_TRAITS_BITSET_REFERENCE
#	define XIEITE_HEADER_TRAITS_BITSET_REFERENCE

#	include <type_traits>
#	include "../concepts/bitset_reference.hpp"

namespace xieite::traits {
	template<typename Type>
	struct BitsetReference
	: std::bool_constant<xieite::concepts::BitsetReference<Type>> {};
}

#endif
