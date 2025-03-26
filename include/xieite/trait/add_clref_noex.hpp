#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CLREF_NOEX
#
#	include "../trait/add_clref_referent.hpp"
#	include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T>
	using add_clref_noex = xieite::add_clref_referent<xieite::add_noex<T>>;
}

#endif
