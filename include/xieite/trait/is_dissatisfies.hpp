#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_DISSATISFIES
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_DISSATISFIES
#
#	include "../trait/is_satisfies_any.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_dissatisfies = !xieite::is_satisfies_any<T, fns...>;
}

#endif
