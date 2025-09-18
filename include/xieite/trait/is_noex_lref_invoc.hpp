#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_LREF_INVOC
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_LREF_INVOC
#
#	include "../trait/is_noex_invoc.hpp"

namespace xieite {
	template<typename T, typename Sig = void()>
	concept is_noex_lref_invoc = xieite::is_noex_invoc<T&, Sig>;
}

#endif
