#ifndef XIEITE_HEADER_TRAITS_IS_POINTER
#	define XIEITE_HEADER_TRAITS_IS_POINTER

#	include <type_traits>
#	include "../concepts/pointer.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsPointer
	: std::bool_constant<xieite::concepts::Pointer<Type>> {};
}

#endif
