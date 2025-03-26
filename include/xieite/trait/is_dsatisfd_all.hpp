#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DSATISFD_ALL
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DSATISFD_ALL
#
#	include "../trait/is_satisfd_any.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dsatisfd_all = !xieite::is_satisfd_any<fn, Ts...>;
}

#endif
