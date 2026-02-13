#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_CRREF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_CRREF
#
#	include "../trait/remove_c.hpp"
#	include "../trait/remove_rref.hpp"

namespace xte {
	template<typename T>
	using remove_crref = xte::remove_rref<xte::remove_c<T>>;
}

#endif
