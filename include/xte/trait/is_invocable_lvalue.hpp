#ifndef DETAIL_XTE_HEADER_TRAIT_IS_INVOCABLE_LVALUE
#	define DETAIL_XTE_HEADER_TRAIT_IS_INVOCABLE_LVALUE
#
#	include "../trait/add_lvalue_ref.hpp"
#	include "../trait/is_invocable.hpp"

namespace xte {
	template<typename T, typename signature_type>
	concept is_invocable_lvalue = xte::is_invocable<xte::add_lvalue_ref<T>, signature_type>;
}

#endif
