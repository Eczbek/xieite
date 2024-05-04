#ifndef XIEITE_HEADER_CONCEPTS_NOT_ALL
#	define XIEITE_HEADER_CONCEPTS_NOT_ALL

namespace xieite::concepts {
	template<typename Type_, template<typename> typename... Traits_>
	concept NotAll = (... || !Traits_<Type_>::value);
}

#endif
