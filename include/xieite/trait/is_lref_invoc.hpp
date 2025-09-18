#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_LREF_INVOC
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_LREF_INVOC
#
#	include "../trait/is_invoc.hpp"

namespace xieite {
	template<typename T, typename Sig = void()>
	concept is_lref_invoc = xieite::is_invoc<T&, Sig>;
}

#endif
