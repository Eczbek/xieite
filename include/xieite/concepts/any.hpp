#ifndef XIEITE_HEADER_CONCEPTS_ANY
#	define XIEITE_HEADER_CONCEPTS_ANY

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept Any = (... || Traits<Type>::value);
}

#endif
