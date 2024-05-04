#ifndef XIEITE_HEADER_CONCEPTS_ALL
#	define XIEITE_HEADER_CONCEPTS_ALL

namespace xieite::concepts {
	template<typename Type_, template<typename> typename... Traits_>
	concept All = (... && Traits_<Type_>::value);
}

#endif
