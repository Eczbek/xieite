#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFD_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFD_ANY
#
#	include "../trait/is_satisfd.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_satisfd_any = (... || xieite::is_satisfd<fn, Ts>);
}

#endif
