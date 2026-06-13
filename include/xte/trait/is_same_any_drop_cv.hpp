#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY_DROP_CV
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY_DROP_CV
#
#	include "../trait/is_same_drop_cv.hpp"

namespace xte {
	template<typename T, typename... Ts>
	concept is_same_any_drop_cv = (... || xte::is_same_drop_cv<T, Ts>);
}

#endif
