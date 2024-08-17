#ifndef XIEITE_HEADER_TRAITS_IS_VOLATILE
#	define XIEITE_HEADER_TRAITS_IS_VOLATILE

#	include <type_traits>
#	include "../concepts/constant.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsVolatile
	: std::bool_constant<xieite::concepts::Volatile<Type>> {};
}

#endif
