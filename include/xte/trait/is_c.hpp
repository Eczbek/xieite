#ifndef DETAIL_XTE_HEADER_TRAIT_IS_C
#	define DETAIL_XTE_HEADER_TRAIT_IS_C

namespace DETAIL_XTE {
	template<typename T>
	constexpr bool is_c = false;

	template<typename T>
	constexpr bool is_c<const T> = true;

	template<typename T>
	constexpr bool is_c<const T&> = true;

	template<typename T>
	constexpr bool is_c<const T&&> = true;
}

namespace xte {
	template<typename T>
	concept is_c = DETAIL_XTE::is_c<T>;
}

#endif
