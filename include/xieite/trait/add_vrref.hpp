#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VRREF
#
#	include "../trait/add_rref.hpp"
#	include "../trait/add_v.hpp"

namespace xieite {
	template<typename T>
	using add_vrref = xieite::add_v<xieite::add_rref<T>>;
}

#endif
