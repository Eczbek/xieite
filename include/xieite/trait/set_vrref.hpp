#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VRREF
#
#	include "../trait/set_v.hpp"
#	include "../trait/set_rref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_vrref = xieite::set_v<qual, xieite::set_rref<qual, T>>;
}

#endif
