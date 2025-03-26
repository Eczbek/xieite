#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_CLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_CLREF
#
#	include "../trait/set_c.hpp"
#	include "../trait/set_lref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_clref = xieite::set_c<qual, xieite::set_lref<qual, T>>;
}

#endif
