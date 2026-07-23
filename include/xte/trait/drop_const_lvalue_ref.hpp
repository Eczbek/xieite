#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CONST_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CONST_LVALUE_REF
#
#	include "../trait/drop_const.hpp"
#	include "../trait/drop_lvalue_ref.hpp"

namespace xte {
	template<typename T>
	using drop_const_lvalue_ref = xte::drop_lvalue_ref<xte::drop_const<T>>;
}

#endif
