#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CONST_RVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CONST_RVALUE_REF_FUNC
#
#	include "../trait/copy_const_func.hpp"
#	include "../trait/copy_rvalue_ref_func.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_const_rvalue_ref_func = xte::copy_rvalue_ref_func<T, xte::copy_const_func<T, U>>;
}

#endif
