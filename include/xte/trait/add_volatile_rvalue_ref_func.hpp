#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_VOLATILE_RVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_ADD_VOLATILE_RVALUE_REF_FUNC
#
#	include "../trait/add_rvalue_ref_func.hpp"
#	include "../trait/add_volatile_func.hpp"

namespace xte {
	template<typename T>
	using add_volatile_rvalue_ref_func = xte::add_rvalue_ref_func<xte::add_volatile_func<T>>;
}

#endif
