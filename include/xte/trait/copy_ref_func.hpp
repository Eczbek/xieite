#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_COPY_REF_FUNC
#
#	include "../trait/add_lvalue_ref_func.hpp"
#	include "../trait/add_rvalue_ref_func.hpp"
#	include "../trait/drop_lvalue_ref_func.hpp"
#	include "../trait/drop_ref_func.hpp"
#	include "../trait/drop_rvalue_ref_func.hpp"
#	include "../trait/is_lvalue_ref_func.hpp"
#	include "../trait/is_rvalue_ref_func.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_const_func = [:xte::is_lvalue_ref_func<T> ? ^^xte::add_lvalue_ref_func<xte::drop_rvalue_ref_func<U>> : (xte::is_rvalue_ref_func<T> ? ^^xte::add_rvalue_ref_func<xte::drop_lvalue_ref_func<U>> : ^^xte::drop_ref_func<U>):];
}

#endif
