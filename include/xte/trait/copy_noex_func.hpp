#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_NOEX_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_COPY_NOEX_FUNC
#
#	include "../trait/add_noex_func.hpp"
#	include "../trait/drop_noex_func.hpp"
#	include "../trait/is_noex_func.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_noex_func = [:xte::is_noex_func<T> ? ^^xte::add_noex_func<U> : ^^xte::drop_noex_func<U>:];
}

#endif
