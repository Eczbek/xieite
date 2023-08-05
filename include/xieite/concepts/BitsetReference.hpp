#ifndef XIEITE_HEADER__CONCEPTS__BITSET_REFERENCE
#	define XIEITE_HEADER__CONCEPTS__BITSET_REFERENCE

#	include "../traits/IsBitsetReference.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept BitsetReference = xieite::traits::IsBitsetReference<Type>::value;
}

#endif
