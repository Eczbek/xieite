#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CRREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CRREF_REFERENT
#
#	include "../trait/rm_c_referent.hpp"
#	include "../trait/rm_rref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_crref_referent = xieite::rm_c_referent<xieite::rm_rref_referent<T>>;
}

#endif
