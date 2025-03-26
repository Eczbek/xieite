#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_V_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_V_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_v_referent.hpp"

namespace xieite {
	template<typename T>
	using add_v_noex = xieite::add_v_referent<xieite::add_noex<T>>;
}

#endif
