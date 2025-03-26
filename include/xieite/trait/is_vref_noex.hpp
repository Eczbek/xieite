#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VREF_NOEX
#
#	include "../trait/is_m_fn_ptr.hpp"
#	include "../trait/is_noex.hpp"
#	include "../trait/is_vref_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_vref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_vref_referent<T>) && xieite::is_noex<T>;
}

#endif
