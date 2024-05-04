#ifndef XIEITE_HEADER_CONCEPTS_ANY
#	define XIEITE_HEADER_CONCEPTS_ANY

namespace xieite::concepts {
	template<typename Type_, template<typename> typename... Traits_>
	concept Any = (... || Traits_<Type_>::value);
}

#endif
