#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VLREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VLREF_REFERENT
#
#	include "../trait/set_v_referent.hpp"
#	include "../trait/set_lref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_vlref_referent = xieite::set_v_referent<qual, xieite::set_lref_referent<qual, T>>;
}

#endif
