#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CLREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CLREF_REFERENT
#
#	include "../trait/add_c_referent.hpp"
#	include "../trait/add_lref_referent.hpp"

namespace xieite {
	template<typename T>
	using add_clref_referent = xieite::add_c_referent<xieite::add_lref_referent<T>>;
}

#endif
