#ifndef DETAIL_XTE_HEADER_TRAITS_ADD_VLREF
#	define DETAIL_XTE_HEADER_TRAITS_ADD_VLREF
#
#	include "../trait/add_v.hpp"
#	include "../trait/add_lref.hpp"

namespace xte {
	template<typename T>
	using add_vlref = xte::add_lref<xte::add_v<T>>;
}

#endif
