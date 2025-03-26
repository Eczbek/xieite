#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CRREF
#
#	include "../trait/is_rref_referent.hpp"
#	include "../trait/is_var_c.hpp"

namespace xieite {
	template<typename T>
	concept is_var_crref = xieite::is_var_c<T> && xieite::is_rref_referent<T>;
}

#endif
