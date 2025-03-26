#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DSATISFD
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DSATISFD
#
#	include "../trait/is_satisfd.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dsatisfd = !xieite::is_satisfd<fn, Ts...>;
}

#endif
