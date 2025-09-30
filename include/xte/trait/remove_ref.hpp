#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_REF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_REF
#
#	include "../trait/remove_lref.hpp"
#	include "../trait/remove_rref.hpp"

namespace xte {
	template<typename T>
	using remove_ref = xte::remove_rref<xte::remove_lref<T>>;
}

#endif
