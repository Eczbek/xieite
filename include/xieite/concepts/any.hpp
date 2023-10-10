#ifndef XIEITE_HEADER__CONCEPTS__ANY
#	define XIEITE_HEADER__CONCEPTS__ANY

#	include <concepts>

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept Any = (... && requires {
		{ Traits<Type>::value } -> std::convertible_to<bool>;
	}) && (... || Traits<Type>::value);
}

#endif
