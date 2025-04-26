#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFIED_ALL
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFIED_ALL
#
#	include "../trait/is_satisfied.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_satisfied_all = (... && xieite::is_satisfied<fn, Ts>);
}

#endif
