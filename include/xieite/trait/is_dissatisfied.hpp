#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DISSATISFIED
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DISSATISFIED
#
#	include "../trait/is_satisfied.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dissatisfied = !xieite::is_satisfied<fn, Ts...>;
}

#endif
