#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DISSATISFIED_ALL
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DISSATISFIED_ALL
#
#	include "../trait/is_satisfied_any.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dissatisfied_all = !xieite::is_satisfied_any<fn, Ts...>;
}

#endif
