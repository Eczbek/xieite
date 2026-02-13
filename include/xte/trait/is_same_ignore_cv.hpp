#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME_IGNORE_CV
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME_IGNORE_CV
#
#	include "../trait/is_same.hpp"
#	include "../trait/remove_cv.hpp"

namespace xte {
	template<typename T, typename... Us>
	concept is_same_ignore_cv = xte::is_same<xte::remove_cv<T>, xte::remove_cv<Us>...>;
}

#endif
