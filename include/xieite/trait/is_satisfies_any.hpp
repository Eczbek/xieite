#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFIES_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFIES_ANY
#
#	include "../trait/is_satisfies.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_satisfies_any = (... || xieite::is_satisfies<T, fns>);
}

#endif
