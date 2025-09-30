#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_CV
#	define DETAIL_XTE_HEADER_TRAIT_ADD_CV
#
#	include "../trait/add_c.hpp"
#	include "../trait/add_v.hpp"

namespace xte {
	template<typename T>
	using add_cv = xte::add_v<xte::add_c<T>>;
}

#endif
