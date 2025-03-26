#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CVLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CVLREF
#
#	include "../trait/add_cv.hpp"
#	include "../trait/add_lref.hpp"

namespace xieite {
	template<typename T>
	using add_cvlref = xieite::add_cv<xieite::add_lref<T>>;
}

#endif
