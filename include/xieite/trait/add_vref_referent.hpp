#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VREF_REFERENT
#
#	include "../trait/add_ref_referent.hpp"
#	include "../trait/add_v_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_vref_referent = xieite::add_v_referent<xieite::add_ref_referent<T, U>>;
}

#endif
