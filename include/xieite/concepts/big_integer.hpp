#ifndef XIEITE_HEADER_CONCEPTS_BIG_INTEGER
#	define XIEITE_HEADER_CONCEPTS_BIG_INTEGER

#	include "../traits/is_big_integer.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept BigInteger = xieite::traits::IsBigInteger<Type>::value;
}

#endif
