#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_CV
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_CV
#
#	include "../trait/remove_c.hpp"
#	include "../trait/remove_v.hpp"

namespace xte {
	template<typename T>
	using remove_cv = xte::remove_v<xte::remove_c<T>>;
}

#endif
