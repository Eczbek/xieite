#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DISSATISFIES_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DISSATISFIES_ANY
#
#	include "../trait/is_satisfies.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_dissatisfies_any = !xieite::is_satisfies<T, fns...>;
}

#endif
