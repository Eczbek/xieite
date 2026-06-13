#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME_DROP_CVREF
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME_DROP_CVREF
#
#	include "../trait/drop_cvref.hpp"
#	include "../trait/is_same.hpp"

namespace xte {
	template<typename T, typename... Ts>
	concept is_same_drop_cvref = xte::is_same<xte::drop_cvref<T>, xte::drop_cvref<Ts>...>;
}

#endif
