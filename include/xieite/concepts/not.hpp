#ifndef XIEITE_HEADER_CONCEPTS_NOT
#	define XIEITE_HEADER_CONCEPTS_NOT

namespace xieite::concepts {
	template<typename Type, template<typename> typename Trait>
	concept Not = requires {
		{ Trait<Type>::value } -> std::convertible_to<bool>;
	} && !Trait<Type>::value;
}

#endif
