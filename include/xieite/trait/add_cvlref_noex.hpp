#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CVLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CVLREF_NOEX
#
#	include "../trait/add_cvlref_referent.hpp"
#	include "../trait/add_noex.hpp"

namespace xieite {
	template<typename T>
	using add_cvlref_noex = xieite::add_cvlref_referent<xieite::add_noex<T>>;
}

#endif
