#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VLREF_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_vlref_referent.hpp"

namespace xieite {
	template<typename T>
	using add_vlref_noex = xieite::add_vlref_referent<xieite::add_noex<T>>;
}

#endif
