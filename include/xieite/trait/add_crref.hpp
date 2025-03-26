#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CRREF
#
#	include "../trait/add_c.hpp"
#	include "../trait/add_rref.hpp"

namespace xieite {
	template<typename T>
	using add_crref = xieite::add_c<xieite::add_rref<T>>;
}

#endif
