#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CRREF_NOEX
#
#	include "../trait/add_crref_referent.hpp"
#	include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T>
	using add_crref_noex = xieite::add_crref_referent<xieite::add_noex<T>>;
}

#endif
