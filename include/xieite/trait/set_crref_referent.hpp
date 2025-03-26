#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_CRREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_CRREF_REFERENT
#
#	include "../trait/set_c_referent.hpp"
#	include "../trait/set_rref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_crref_referent = xieite::set_c_referent<qual, xieite::set_rref_referent<qual, T>>;
}

#endif
