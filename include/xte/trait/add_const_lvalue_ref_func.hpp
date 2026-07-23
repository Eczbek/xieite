#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_CONST_LVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_ADD_CONST_LVALUE_REF_FUNC
#
#	include "../trait/add_const_func.hpp"
#	include "../trait/add_lvalue_ref_func.hpp"

namespace xte {
	template<typename T>
	using add_const_lvalue_ref_func = xte::add_lvalue_ref_func<xte::add_const_func<T>>;
}

#endif
