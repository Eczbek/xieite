#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VLREF
#
#	include "../trait/set_v.hpp"
#	include "../trait/set_lref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_vlref = xieite::set_v<qual, xieite::set_lref<qual, T>>;
}

#endif
