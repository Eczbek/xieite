#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CLREF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CLREF
#
#	include "../trait/copy_c.hpp"
#	include "../trait/copy_lref.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_clref = xte::copy_lref<T, xte::copy_c<T, U>>;
}

#endif
