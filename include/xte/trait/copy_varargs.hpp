#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_VARARGS
#	define DETAIL_XTE_HEADER_TRAIT_COPY_VARARGS
#
#	include "../trait/add_varargs.hpp"
#	include "../trait/drop_varargs.hpp"
#	include "../trait/is_varargs.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_varargs = [:xte::is_varargs<T> ? ^^xte::add_varargs<U> : ^^xte::drop_varargs<U>:];
}

#endif
