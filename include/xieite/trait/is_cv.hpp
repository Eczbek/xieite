#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CV
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CV
#
#	include "../trait/is_c.hpp"
#	include "../trait/is_v.hpp"

namespace xieite {
	template<typename T>
	concept is_cv = xieite::is_c<T> && xieite::is_v<T>;
}

#endif
