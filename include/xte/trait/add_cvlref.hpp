#ifndef DETAIL_XTE_HEADER_TRAITS_ADD_CVLREF
#	define DETAIL_XTE_HEADER_TRAITS_ADD_CVLREF
#
#	include "../trait/add_cv.hpp"
#	include "../trait/add_lref.hpp"

namespace xte {
	template<typename T>
	using add_cvlref = xte::add_lref<xte::add_cv<T>>;
}

#endif
