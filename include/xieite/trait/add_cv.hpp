#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CV
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CV
#
#	include "../trait/add_c.hpp"
#	include "../trait/add_v.hpp"

namespace xieite {
	template<typename T>
	using add_cv = xieite::add_c<xieite::add_v<T>>;
}

#endif
