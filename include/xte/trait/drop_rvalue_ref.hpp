#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_RVALUE_REF

namespace DETAIL_XTE::drop_rvalue_ref {
	template<typename T>
	constexpr auto impl = ^^T;

	template<typename T>
	constexpr auto impl<T&&> = ^^T;
}

namespace xte {
	template<typename T>
	using drop_rvalue_ref = [:DETAIL_XTE::drop_rvalue_ref::impl<T>:];
}

#endif
