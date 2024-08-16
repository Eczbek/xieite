#ifndef XIEITE_HEADER_TRAITS_IS_INTEGRAL
#	define XIEITE_HEADER_TRAITS_IS_INTEGRAL

#	include <type_traits>
#	include "../concepts/integral.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsIntegral
	: std::bool_constant<xieite::concepts::Integral<Type>> {};
}

#endif
