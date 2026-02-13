#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CVLREF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CVLREF
#
#	include "../trait/copy_cv.hpp"
#	include "../trait/copy_lref.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_cvlref = xte::copy_lref<T, xte::copy_cv<T, U>>;
}

#endif
