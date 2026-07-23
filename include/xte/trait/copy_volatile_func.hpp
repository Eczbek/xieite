#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_VOLATILE_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_COPY_VOLATILE_FUNC
#
#	include "../trait/add_volatile_func.hpp"
#	include "../trait/drop_volatile_func.hpp"
#	include "../trait/is_volatile_func.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_volatile_func = [:xte::is_volatile_func<T> ? ^^xte::add_volatile_func<U> : ^^xte::drop_volatile_func<U>:];
}

#endif
