#ifndef DETAIL_XTE_HEADER_TRAIT_IS_LREF
#	define DETAIL_XTE_HEADER_TRAIT_IS_LREF

namespace DETAIL_XTE {
	template<typename>
	constexpr bool is_lref = false;

	template<typename T>
	constexpr bool is_lref<T&> = true;
}

namespace xte {
	template<typename T>
	concept is_lref = DETAIL_XTE::is_lref<T>;
}

#endif
