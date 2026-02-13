#ifndef DETAIL_XTE_HEADER_TRAITS_ADD_CRREF
#	define DETAIL_XTE_HEADER_TRAITS_ADD_CRREF
#
#	include "../trait/add_c.hpp"
#	include "../trait/add_rref.hpp"

namespace xte {
	template<typename T>
	using add_crref = xte::add_rref<xte::add_c<T>>;
}

#endif
