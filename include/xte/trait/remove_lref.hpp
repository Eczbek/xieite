#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_LREF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_LREF

namespace DETAIL_XTE {
	template<typename T>
	constexpr auto remove_lref = ^^T;

	template<typename T>
	constexpr auto remove_lref<T&> = ^^T;
}

namespace xte {
	template<typename T>
	using remove_lref = [:DETAIL_XTE::remove_lref<T>:];
}

#endif
