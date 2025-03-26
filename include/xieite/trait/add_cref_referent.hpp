#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CREF_REFERENT
#
#	include "../trait/add_c_referent.hpp"
#	include "../trait/add_ref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_cref_referent = xieite::add_c_referent<xieite::add_ref_referent<T, U>>;
}

#endif
