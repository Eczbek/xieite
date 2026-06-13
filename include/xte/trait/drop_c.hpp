#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_C
#	define DETAIL_XTE_HEADER_TRAIT_DROP_C

namespace DETAIL_XTE {
	template<typename T>
	constexpr auto drop_c = ^^T;

	template<typename T>
	constexpr auto drop_c<const T> = ^^T;

	template<typename T>
	constexpr auto drop_c<const T&> = ^^T&;

	template<typename T>
	constexpr auto drop_c<const T&&> = ^^T&&;
}

namespace xte {
	template<typename T>
	using drop_c = [:DETAIL_XTE::drop_c<T>:];
}

#endif
