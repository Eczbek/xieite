#ifndef XIEITE_HEADER_TRAITS_IS_ARITHMETIC
#	define XIEITE_HEADER_TRAITS_IS_ARITHMETIC

#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsArithmetic
	: std::bool_constant<xieite::concepts::Arithmetic<Type>> {};
}

#endif
