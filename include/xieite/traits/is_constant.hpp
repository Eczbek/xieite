#ifndef XIEITE_HEADER_TRAITS_IS_CONSTANT
#	define XIEITE_HEADER_TRAITS_IS_CONSTANT

#	include <type_traits>
#	include "../concepts/constant.hpp"

namespace xieite::traits {
	template<typename Type>
	struct IsConstant
	: std::bool_constant<xieite::concepts::Constant<Type>> {};
}

#endif
