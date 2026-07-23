#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CVREF
#	define DETAIL_XTE_HEADER_TRAIT_IS_CVREF
#
#	include "../trait/is_cv.hpp"
#	include "../trait/is_ref.hpp"

namespace xte {
	template<typename T>
	concept is_cvref = xte::is_cv<T> && xte::is_ref<T>;
}

#endif
