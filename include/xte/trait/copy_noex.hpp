#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_COPY_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/drop_noex.hpp"
#	include "../trait/is_noex.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_noex = [:xte::is_noex<T> ? ^^xte::add_noex<U> : ^^xte::drop_noex<U>:];
}

#endif
