#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME_IGNORE_CVREF
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME_IGNORE_CVREF
#
#	include "../trait/is_same.hpp"
#	include "../trait/remove_cvref.hpp"

namespace xte {
	template<typename T, typename... Us>
	concept is_same_ignore_cvref = xte::is_same<xte::remove_cvref<T>, xte::remove_cvref<Us>...>;
}

#endif
