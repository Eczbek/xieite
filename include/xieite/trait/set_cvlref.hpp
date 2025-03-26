#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_CVLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_CVLREF
#
#	include "../trait/set_cv.hpp"
#	include "../trait/set_lref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_cvlref = xieite::set_cv<qual, xieite::set_lref<qual, T>>;
}

#endif
