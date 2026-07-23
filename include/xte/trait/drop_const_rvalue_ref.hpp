#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CONST_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CONST_RVALUE_REF
#
#	include "../trait/drop_const.hpp"
#	include "../trait/drop_rvalue_ref.hpp"

namespace xte {
	template<typename T>
	using drop_const_rvalue_ref = xte::drop_rvalue_ref<xte::drop_const<T>>;
}

#endif
