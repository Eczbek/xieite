#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFD_ALL
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFD_ALL
#
#	include "../trait/is_satisfd.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_satisfd_all = (... && xieite::is_satisfd<fn, Ts>);
}

#endif
