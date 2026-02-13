#ifndef DETAIL_XTE_HEADER_TRAIT_IS_RREF
#	define DETAIL_XTE_HEADER_TRAIT_IS_RREF

namespace DETAIL_XTE {
	template<typename>
	constexpr bool is_rref = false;

	template<typename T>
	constexpr bool is_rref<T&> = true;
}

namespace xte {
	template<typename T>
	concept is_rref = DETAIL_XTE::is_rref<T>;
}

#endif
