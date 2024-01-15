#ifndef XIEITE_HEADER_TRAITS_IS_BIG_INTEGER
#	define XIEITE_HEADER_TRAITS_IS_BIG_INTEGER

#	include <concepts>
#	include <type_traits>

namespace xieite::math {
	template<std::unsigned_integral>
	struct BigInteger;
}

namespace xieite::traits {
	template<typename Type>
	struct IsBigInteger
	: std::false_type {};

	template<std::unsigned_integral Word>
	struct IsBigInteger<xieite::math::BigInteger<Word>>
	: std::true_type {};
}

#endif
