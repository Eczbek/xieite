#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFIED_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFIED_ANY
#
#	include "../trait/is_satisfied.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_satisfied_any = (... || xieite::is_satisfied<fn, Ts>);
}

#endif
