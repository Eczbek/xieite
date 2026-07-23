#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_VOLATILE
#	define DETAIL_XTE_HEADER_TRAIT_COPY_VOLATILE
#
#	include "../trait/add_volatile.hpp"
#	include "../trait/drop_volatile.hpp"
#	include "../trait/is_volatile.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_volatile = [:xte::is_volatile<T> ? ^^xte::add_volatile<U> : ^^xte::drop_volatile<U>:];
}

#endif
