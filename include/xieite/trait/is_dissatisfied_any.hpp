#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DISSATISFIED_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DISSATISFIED_ANY
#
#	include "../trait/is_satisfied_all.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dissatisfied_any = !xieite::is_satisfied_all<fn, Ts...>;
}

#endif
