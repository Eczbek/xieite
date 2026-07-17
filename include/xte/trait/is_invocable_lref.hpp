#ifndef DETAIL_XTE_HEADER_TRAIT_IS_INVOCABLE_LREF
#	define DETAIL_XTE_HEADER_TRAIT_IS_INVOCABLE_LREF
#
#	include "../trait/add_lvalue_ref.hpp"
#	include "../trait/is_invocable.hpp"

namespace xte {
	template<typename Func, typename Signature>
	concept is_invocable_lvalue_ref = xte::is_invocable<xte::add_lvalue_ref<Func>, Signature>;
}

#endif
