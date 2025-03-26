#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SATISF_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SATISF_ANY
#
#	include "../trait/is_satisf.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_satisf_any = (... || xieite::is_satisf<T, fns>);
}

#endif
