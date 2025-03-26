#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VRREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VRREF_REFERENT
#
#	include "../trait/add_rref_referent.hpp"
#	include "../trait/add_v_referent.hpp"

namespace xieite {
	template<typename T>
	using add_vrref_referent = xieite::add_v_referent<xieite::add_rref_referent<T>>;
}

#endif
