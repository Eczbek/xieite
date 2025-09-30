#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY
#
#	include "../trait/is_same.hpp"

namespace xte {
	template<typename T, typename... Us>
	concept is_same_any = (... || xte::is_same<T, Us>);
}

#endif
