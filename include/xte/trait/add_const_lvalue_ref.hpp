#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_CONST_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_ADD_CONST_LVALUE_REF
#
#	include "../trait/add_const.hpp"
#	include "../trait/add_lvalue_ref.hpp"

namespace xte {
	template<typename T>
	using add_const_lvalue_ref = xte::add_lvalue_ref<xte::add_const<T>>;
}

#endif
