#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_RREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_RREF_NOEX
#
#	include "../trait/set_rref_referent.hpp"
#	include "../trait/set_noex.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_rref_noex = xieite::set_rref_referent<qual, xieite::set_noex<qual, T>>;
}

#endif
