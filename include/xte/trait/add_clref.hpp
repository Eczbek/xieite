#ifndef DETAIL_XTE_HEADER_TRAITS_ADD_CLREF
#	define DETAIL_XTE_HEADER_TRAITS_ADD_CLREF
#
#	include "../trait/add_c.hpp"
#	include "../trait/add_lref.hpp"

namespace xte {
	template<typename T>
	using add_clref = xte::add_lref<xte::add_c<T>>;
}

#endif
