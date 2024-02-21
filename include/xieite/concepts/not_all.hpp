#ifndef XIEITE_HEADER_CONCEPTS_NOT_ALL
#	define XIEITE_HEADER_CONCEPTS_NOT_ALL

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept NotAll = (... || !Traits<Type>::value);
}

#endif
