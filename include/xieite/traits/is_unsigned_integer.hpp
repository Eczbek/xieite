#ifndef XIEITE_HEADER_TRAITS_IS_UNSIGNED_INTEGRAL
#	define XIEITE_HEADER_TRAITS_IS_UNSIGNED_INTEGRAL

#	include <type_traits>
#	include "../concepts/unsigned_integral.hpp"

namespace xieite::traits {
	template<typename Type_>
	struct IsUnsignedIntegral
	: std::bool_constant<xieite::concepts::UnsignedIntegral<Type_>> {};
}

#endif
