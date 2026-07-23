#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CREF
#	define DETAIL_XTE_HEADER_TRAIT_IS_CREF
#
#	include "../trait/is_const.hpp"
#	include "../trait/is_ref.hpp"

namespace xte {
	template<typename T>
	concept is_cref = xte::is_const<T> && xte::is_ref<T>;
}

#endif
