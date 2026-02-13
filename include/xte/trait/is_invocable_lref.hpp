#ifndef DETAIL_XTE_HEADER_TRAIT_IS_INVOCABLE_LREF
#	define DETAIL_XTE_HEADER_TRAIT_IS_INVOCABLE_LREF
#
#	include "../trait/add_lref.hpp"
#	include "../trait/is_invocable.hpp"

namespace xte {
	template<typename Func, typename Signature>
	concept is_invocable_lref = xte::is_invocable<xte::add_lref<Func>, Signature>;
}

#endif
