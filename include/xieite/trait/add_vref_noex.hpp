#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VREF_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_vref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_vref_noex = xieite::add_vref_referent<T, xieite::add_noex<U>>;
}

#endif
