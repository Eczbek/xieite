#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CVRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CVRREF
#
#	include "../trait/add_cv.hpp"
#	include "../trait/add_rref.hpp"

namespace xieite {
	template<typename T>
	using add_cvrref = xieite::add_cv<xieite::add_rref<T>>;
}

#endif
