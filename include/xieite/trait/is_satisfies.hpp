#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFIES
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SATISFIES
#
#	include "../trait/is_satisfied.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_satisfies = (... && xieite::is_satisfied<fns, T>);
}

#endif
