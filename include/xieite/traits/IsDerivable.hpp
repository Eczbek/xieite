#ifndef XIEITE_HEADER__TRAITS__IS_DERIVABLE
#	define XIEITE_HEADER__TRAITS__IS_DERIVABLE

#	include <type_traits>

namespace xieite::traits {
	template<typename Type>
	struct IsDerivable
	: std::bool_constant<std::is_class_v<Type> && !std::is_final_v<Type>> {};
}

#endif
