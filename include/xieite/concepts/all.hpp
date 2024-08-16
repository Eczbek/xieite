#ifndef XIEITE_HEADER_CONCEPTS_ALL
#	define XIEITE_HEADER_CONCEPTS_ALL

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept All = (... && Traits<Type>::value);
}

#endif
