#ifndef DETAIL_XIEITE_HEADER_TRAIT_COLLAPSE_REF
#	define DETAIL_XIEITE_HEADER_TRAIT_COLLAPSE_REF
#
#	include "../trait/add_rref.hpp"
#	include "../trait/cp_cvlref.hpp"

namespace xieite {
	template<typename T, typename U>
	using collapse_ref = xieite::cp_cvlref<T, xieite::add_rref<U>>;
}

#endif
