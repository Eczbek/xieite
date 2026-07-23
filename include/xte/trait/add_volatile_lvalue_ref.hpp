#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_VOLATILE_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_ADD_VOLATILE_LVALUE_REF
#
#	include "../trait/add_lvalue_ref.hpp"
#	include "../trait/add_volatile.hpp"

namespace xte {
	template<typename T>
	using add_volatile_lvalue_ref = xte::add_lvalue_ref<xte::add_volatile<T>>;
}

#endif
