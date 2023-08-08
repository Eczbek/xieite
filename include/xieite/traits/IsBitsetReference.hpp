#ifndef XIEITE_HEADER__TRAITS__IS_BITSET_REFERENCE
#	define XIEITE_HEADER__TRAITS__IS_BITSET_REFERENCE

#	include <type_traits>
#	include "../concepts/BitsetReference.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsBitsetReference
	: std::bool_constant<xieite::concepts::BitsetReference<Type>> {};
}

#endif
