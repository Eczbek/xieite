#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CV
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CV
#
#	include "../trait/set_v_referent.hpp"
#	include "../trait/set_var_c.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_cv = xieite::set_var_c<qual, xieite::set_v_referent<qual, T>>;
}

#endif
