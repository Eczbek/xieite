#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CONST
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CONST
#
#	include "../trait/add_const.hpp"
#	include "../trait/drop_const.hpp"
#	include "../trait/is_const.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_const = [:xte::is_const<T> ? ^^xte::add_const<U> : ^^xte::drop_const<U>:];
}

#endif
