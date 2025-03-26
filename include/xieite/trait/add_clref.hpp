#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CLREF
#
#	include "../trait/add_c.hpp"
#	include "../trait/add_lref.hpp"

namespace xieite {
	template<typename T>
	using add_clref = xieite::add_c<xieite::add_lref<T>>;
}

#endif
