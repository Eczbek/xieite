#ifndef DETAIL_XTE_HEADER_TRAIT_IS_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_IS_RVALUE_REF

namespace DETAIL_XTE::is_rvalue_ref {
	template<typename>
	constexpr bool impl = false;

	template<typename T>
	constexpr bool impl<T&&> = true;
}

namespace xte {
	template<typename T>
	concept is_rvalue_ref = DETAIL_XTE::is_rvalue_ref::impl<T>;
}

#endif
