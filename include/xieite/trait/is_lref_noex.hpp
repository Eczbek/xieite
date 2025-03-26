#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_LREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_LREF_NOEX
#
#	include "../trait/is_lref_referent.hpp"
#	include "../trait/is_m_fn_ptr.hpp"
#	include "../trait/is_noex.hpp"

namespace xieite {
	template<typename T>
	concept is_lref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_lref_referent<T>) && xieite::is_noex<T>;
}

#endif
