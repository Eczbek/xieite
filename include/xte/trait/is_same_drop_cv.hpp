#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME_DROP_CV
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME_DROP_CV
#
#	include "../trait/drop_cv.hpp"
#	include "../trait/is_same.hpp"

namespace xte {
	template<typename T, typename... Ts>
	concept is_same_drop_cv = xte::is_same<xte::drop_cv<T>, xte::drop_cv<Ts>...>;
}

#endif
