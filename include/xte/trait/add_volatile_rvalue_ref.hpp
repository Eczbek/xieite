#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_VOLATILE_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_ADD_VOLATILE_RVALUE_REF
#
#	include "../trait/add_rvalue_ref.hpp"
#	include "../trait/add_volatile.hpp"

namespace xte {
	template<typename T>
	using add_volatile_rvalue_ref = xte::add_rvalue_ref<xte::add_volatile<T>>;
}

#endif
