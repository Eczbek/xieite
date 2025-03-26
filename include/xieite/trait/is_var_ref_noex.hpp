#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_REF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_REF_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_ref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_ref_noex = xieite::is_var_ref<T> && xieite::is_noex<T>;
}

#endif
