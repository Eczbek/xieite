#ifndef XIEITE_HEADER_CONCEPTS_ALL
#	define XIEITE_HEADER_CONCEPTS_ALL

#	include <concepts>

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept All = (... && requires {
		{ Traits<Type>::value } -> std::convertible_to<bool>;
	}) && (... && Traits<Type>::value);
}

#endif
