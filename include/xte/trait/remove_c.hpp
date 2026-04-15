#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_C
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_C

namespace DETAIL_XTE {
	template<typename T>
	constexpr auto remove_c = ^^T;

	template<typename T>
	constexpr auto remove_c<const T> = ^^T;

	template<typename T>
	constexpr auto remove_c<const T&> = ^^T&;

	template<typename T>
	constexpr auto remove_c<const T&&> = ^^T&&;
}

namespace xte {
	template<typename T>
	using remove_c = [:DETAIL_XTE::remove_c<T>:];
}

#endif
