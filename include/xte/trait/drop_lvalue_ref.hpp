#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_LVALUE_REF

namespace DETAIL_XTE::drop_lvalue_ref {
	template<typename T>
	constexpr auto impl = ^^T;

	template<typename T>
	constexpr auto impl<T&> = ^^T;
}

namespace xte {
	template<typename T>
	using drop_lvalue_ref = [:DETAIL_XTE::drop_lvalue_ref::impl<T>:];
}

#endif
