#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_C_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_C_NOEX
#
#	include "../trait/add_c_referent.hpp"
#	include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T>
	using add_c_noex = xieite::add_c_referent<xieite::add_noex<T>>;
}

#endif
