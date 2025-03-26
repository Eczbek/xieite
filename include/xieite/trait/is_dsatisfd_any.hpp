#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DSATISFD_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DSATISFD_ANY
#
#	include "../trait/is_satisfd_all.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dsatisfd_any = !xieite::is_satisfd_all<fn, Ts...>;
}

#endif
