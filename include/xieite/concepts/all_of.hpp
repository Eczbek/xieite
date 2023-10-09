#ifndef XIEITE_HEADER__CONCEPTS__ALL_OF
#	define XIEITE_HEADER__CONCEPTS__ALL_OF

#	include <concepts>

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept AllOf = (... && requires {
		{ Traits<Type>::value } -> std::convertible_to<bool>;
	}) && (... && Traits<Type>::value);
}

#endif
