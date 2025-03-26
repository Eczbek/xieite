#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CVLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CVLREF
#
#	include "../trait/is_cv.hpp"
#	include "../trait/is_lref.hpp"

namespace xieite {
	template<typename T>
	concept is_cvlref = xieite::is_cv<T> && xieite::is_lref<T>;
}

#endif
