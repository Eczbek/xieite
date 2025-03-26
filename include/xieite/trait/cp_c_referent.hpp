#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_C_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_C_REFERENT
#
#	include "../trait/set_c_referent.hpp"
#	include "../trait/is_c_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_c_referent = xieite::set_c_referent<xieite::is_c_referent<T>, U>;
}

#endif
