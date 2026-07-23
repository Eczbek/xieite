#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CREF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_CREF_FUNC
#
#	include "../trait/is_const_func.hpp"
#	include "../trait/is_ref_func.hpp"

namespace xte {
	template<typename T>
	concept is_cref_func = xte::is_const_func<T> && xte::is_ref_func<T>;
}

#endif
