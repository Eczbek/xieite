#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_VARIADIC_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_COPY_VARIADIC_FUNC
#
#	include "../trait/add_variadic_func.hpp"
#	include "../trait/drop_variadic_func.hpp"
#	include "../trait/is_variadic_func.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_variadic_func = [:xte::is_variadic_func<T> ? ^^xte::add_variadic_func<U> : ^^xte::drop_variadic_func<U>:];
}

#endif
