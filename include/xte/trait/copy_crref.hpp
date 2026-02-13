#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CRREF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CRREF
#
#	include "../trait/copy_c.hpp"
#	include "../trait/copy_rref.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_crref = xte::copy_rref<T, xte::copy_c<T, U>>;
}

#endif
