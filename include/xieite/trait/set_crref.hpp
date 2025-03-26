#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_CRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_CRREF
#
#	include "../trait/set_c.hpp"
#	include "../trait/set_rref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_crref = xieite::set_c<qual, xieite::set_rref<qual, T>>;
}

#endif
