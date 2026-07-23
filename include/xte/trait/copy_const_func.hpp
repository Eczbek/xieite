#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CONST_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CONST_FUNC
#
#	include "../trait/add_const_func.hpp"
#	include "../trait/drop_const_func.hpp"
#	include "../trait/is_const_func.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_const_func = [:xte::is_const_func<T> ? ^^xte::add_const_func<U> : ^^xte::drop_const_func<U>:];
}

#endif
