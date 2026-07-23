#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_CONST_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_ADD_CONST_RVALUE_REF
#
#	include "../trait/add_const.hpp"
#	include "../trait/add_rvalue_ref.hpp"

namespace xte {
	template<typename T>
	using add_const_rvalue_ref = xte::add_rvalue_ref<xte::add_const<T>>;
}

#endif
