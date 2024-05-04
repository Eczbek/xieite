#ifndef XIEITE_HEADER_CONCEPTS_NONE
#	define XIEITE_HEADER_CONCEPTS_NONE

namespace xieite::concepts {
	template<typename Type_, template<typename> typename... Traits_>
	concept None = (... && !Traits_<Type_>::value);
}

#endif
