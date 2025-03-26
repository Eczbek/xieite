#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_CRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_CRREF_NOEX
#
#	include "../trait/set_crref_referent.hpp"
#	include "../trait/set_noex.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_crref_noex = xieite::set_crref_referent<qual, xieite::set_noex<qual, T>>;
}

#endif
