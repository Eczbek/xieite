#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CV
#	define DETAIL_XTE_HEADER_TRAIT_IS_CV
#
#	include "../trait/is_c.hpp"
#	include "../trait/is_v.hpp"
#	include "../util/types.hpp"

namespace xte {
	template<typename T, xte::uz index = -1uz>
	concept is_cv = xte::is_c<T, index> && xte::is_v<T, index>;
}

#endif
