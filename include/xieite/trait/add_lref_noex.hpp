#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_LREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_LREF_NOEX
#
#	include "../trait/add_lref_referent.hpp"
#	include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T>
	using add_lref_noex = xieite::add_lref_referent<xieite::add_noex<T>>;
}

#endif
