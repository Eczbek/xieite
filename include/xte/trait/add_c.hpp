#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_C
#	define DETAIL_XTE_HEADER_TRAIT_ADD_C

namespace DETAIL_XTE {
	template<typename T>
	constexpr auto add_c = ^^const T;

	template<typename T>
	constexpr auto add_c<T&> = ^^const T&;

	template<typename T>
	constexpr auto add_c<T&&> = ^^const T&&;
}

namespace xte {
	template<typename T>
	using add_c = [:DETAIL_XTE::add_c<T>:];
}

#endif
