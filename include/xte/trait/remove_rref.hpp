#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_RREF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_RREF

namespace DETAIL_XTE {
	template<typename T>
	constexpr auto remove_rref = ^^T;

	template<typename T>
	constexpr auto remove_rref<T&&> = ^^T;
}

namespace xte {
	template<typename T>
	using remove_rref = [:DETAIL_XTE::remove_rref<T>:];
}

#endif
