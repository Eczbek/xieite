#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CRREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CRREF_REFERENT
#
#	include "../trait/add_c_referent.hpp"
#	include "../trait/add_rref_referent.hpp"

namespace xieite {
	template<typename T>
	using add_crref_referent = xieite::add_c_referent<xieite::add_rref_referent<T>>;
}

#endif
