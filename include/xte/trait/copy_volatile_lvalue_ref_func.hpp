#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_VOLATILE_LVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_COPY_VOLATILE_LVALUE_REF_FUNC
#
#	include "../trait/copy_lvalue_ref_func.hpp"
#	include "../trait/copy_volatile_func.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_volatile_lvalue_ref_func = xte::copy_lvalue_ref_func<T, xte::copy_volatile_func<T, U>>;
}

#endif
