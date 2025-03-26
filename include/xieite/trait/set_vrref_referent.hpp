#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VRREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VRREF_REFERENT
#
#	include "../trait/set_v_referent.hpp"
#	include "../trait/set_rref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_vrref_referent = xieite::set_v_referent<qual, xieite::set_rref_referent<qual, T>>;
}

#endif
