#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_LREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_LREF_NOEX
#
#	include "../trait/set_lref_referent.hpp"
#	include "../trait/set_noex.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_lref_noex = xieite::set_lref_referent<qual, xieite::set_noex<qual, T>>;
}

#endif
