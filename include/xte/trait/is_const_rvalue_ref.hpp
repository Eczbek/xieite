#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CONST_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_IS_CONST_RVALUE_REF
#
#	include "../trait/is_const.hpp"
#	include "../trait/is_rvalue_ref.hpp"

namespace xte {
	template<typename T>
	concept is_const_rvalue_ref = xte::is_const<T> && xte::is_rvalue_ref<T>;
}

#endif
