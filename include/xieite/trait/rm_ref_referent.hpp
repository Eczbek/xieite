#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_REF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_REF_REFERENT
#
#	include "../trait/rm_lref_referent.hpp"
#	include "../trait/rm_rref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_ref_referent = xieite::rm_lref_referent<xieite::rm_rref_referent<T>>;
}

#endif
