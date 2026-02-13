#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_CVRREF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_CVRREF
#
#	include "../trait/remove_cv.hpp"
#	include "../trait/remove_rref.hpp"

namespace xte {
	template<typename T>
	using remove_cvrref = xte::remove_rref<xte::remove_cv<T>>;
}

#endif
