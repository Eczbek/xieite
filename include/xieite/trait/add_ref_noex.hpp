#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_REF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_REF_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_ref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_ref_noex = xieite::add_ref_referent<T, xieite::add_noex<U>>;
}

#endif
