#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CVRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CVRREF_NOEX
#
#	include "../trait/is_cvrref_referent.hpp"
#	include "../trait/is_m_fn_ptr.hpp"
#	include "../trait/is_noex.hpp"

namespace xieite {
	template<typename T>
	concept is_cvrref_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_cvrref_referent<T>) && xieite::is_noex<T>;
}

#endif
