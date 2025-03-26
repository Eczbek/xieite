#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CREF_NOEX
#
#	include "../trait/add_cref_referent.hpp"
#	include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_cref_noex = xieite::add_cref_referent<T, xieite::add_noex<U>>;
}

#endif
