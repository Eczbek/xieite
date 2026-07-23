#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CREF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CREF_FUNC
#
#	include "../trait/copy_const_func.hpp"
#	include "../trait/copy_ref_func.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_cref_func = xte::copy_ref_func<T, xte::copy_const_func<T, U>>;
}

#endif
