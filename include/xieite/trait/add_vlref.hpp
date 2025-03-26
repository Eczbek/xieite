#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VLREF
#
#	include "../trait/add_lref.hpp"
#	include "../trait/add_v.hpp"

namespace xieite {
	template<typename T>
	using add_vlref = xieite::add_v<xieite::add_lref<T>>;
}

#endif
