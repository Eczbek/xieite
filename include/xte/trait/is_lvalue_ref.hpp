#ifndef DETAIL_XTE_HEADER_TRAIT_IS_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_IS_LVALUE_REF

namespace DETAIL_XTE::is_lvalue_ref {
	template<typename>
	constexpr bool impl = false;

	template<typename T>
	constexpr bool impl<T&> = true;
}

namespace xte {
	template<typename T>
	concept is_lvalue_ref = DETAIL_XTE::is_lvalue_ref::impl<T>;
}

#endif
