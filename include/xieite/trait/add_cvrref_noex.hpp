#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CVRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CVRREF_NOEX
#
#	include "../trait/add_cvrref_referent.hpp"
#	include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T>
	using add_cvrref_noex = xieite::add_cvrref_referent<xieite::add_noex<T>>;
}

#endif
