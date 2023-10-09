#ifndef XIEITE_HEADER__CONCEPTS__ANY_OF
#	define XIEITE_HEADER__CONCEPTS__ANY_OF

#	include <concepts>

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept AnyOf = (... && requires {
		{ Traits<Type>::value } -> std::convertible_to<bool>;
	}) && (... || Traits<Type>::value);
}

#endif
