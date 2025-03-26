#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DSATISF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DSATISF
#
#	include "../trait/is_satisf_any.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_dsatisf = !xieite::is_satisf_any<T, fns...>;
}

#endif
