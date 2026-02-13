#ifndef DETAIL_XTE_HEADER_TRAITS_ADD_CVRREF
#	define DETAIL_XTE_HEADER_TRAITS_ADD_CVRREF
#
#	include "../trait/add_cv.hpp"
#	include "../trait/add_rref.hpp"

namespace xte {
	template<typename T>
	using add_cvrref = xte::add_rref<xte::add_cv<T>>;
}

#endif
