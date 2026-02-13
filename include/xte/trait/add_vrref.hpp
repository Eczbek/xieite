#ifndef DETAIL_XTE_HEADER_TRAITS_ADD_VRREF
#	define DETAIL_XTE_HEADER_TRAITS_ADD_VRREF
#
#	include "../trait/add_v.hpp"
#	include "../trait/add_rref.hpp"

namespace xte {
	template<typename T>
	using add_vrref = xte::add_rref<xte::add_v<T>>;
}

#endif
