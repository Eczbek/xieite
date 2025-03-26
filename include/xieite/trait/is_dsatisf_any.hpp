#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DSATISF_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DSATISF_ANY
#
#	include "../trait/is_satisf.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_dsatisf_any = !xieite::is_satisf<T, fns...>;
}

#endif
