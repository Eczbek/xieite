#ifndef XIEITE_HEADER__TRAITS__IS_DECAYED
#	define XIEITE_HEADER__TRAITS__IS_DECAYED

#	include <concepts>
#	include <type_traits>

namespace xieite::traits {
	template<typename Type>
	struct IsDecayed
	: std::bool_constant<std::same_as<Type, std::decay_t<Type>>> {};
}

#endif
