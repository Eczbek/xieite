#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_CVLREF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_CVLREF
#
#	include "../trait/remove_cv.hpp"
#	include "../trait/remove_lref.hpp"

namespace xte {
	template<typename T>
	using remove_cvlref = xte::remove_lref<xte::remove_cv<T>>;
}

#endif
