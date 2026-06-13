#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_RREF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_RREF

namespace DETAIL_XTE {
	template<typename T>
	constexpr auto remove_rref = ^^T;

	template<typename T>
	constexpr auto remove_rref<T&&> = ^^T;
}

namespace xte {
	template<typename T>
	using drop_rref = [:DETAIL_XTE::remove_rref<T>:];
}

#endif
