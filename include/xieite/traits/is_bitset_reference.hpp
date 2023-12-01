#ifndef XIEITE_HEADER_TRAITS_IS_BITSET_REFERENCE
#	define XIEITE_HEADER_TRAITS_IS_BITSET_REFERENCE

#	include <type_traits>
#	include "../concepts/bitset_reference.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsBitsetReference
	: std::bool_constant<xieite::concepts::BitsetReference<Type>> {};
}

#endif
