#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SATISF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SATISF
#
#	include "../trait/is_satisfd.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_satisf = (... && xieite::is_satisfd<fns, T>);
}

#endif
