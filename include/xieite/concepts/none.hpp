#ifndef XIEITE_HEADER_CONCEPTS_NONE
#	define XIEITE_HEADER_CONCEPTS_NONE

namespace xieite::concepts {
	template<typename Type, template<typename> typename... Traits>
	concept None = (... && !Traits<Type>::value);
}

#endif
