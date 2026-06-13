#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY_DROP_CVREF
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY_DROP_CVREF
#
#	include "../trait/is_same_drop_cvref.hpp"

namespace xte {
	template<typename T, typename... Ts>
	concept is_same_any_drop_cvref = (... || xte::is_same_drop_cvref<T, Ts>);
}

#endif
