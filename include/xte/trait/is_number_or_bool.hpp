#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NUMBER_OR_BOOL
#	define DETAIL_XTE_HEADER_TRAIT_IS_NUMBER_OR_BOOL
#
#	include "../trait/is_number.hpp"
#	include "../trait/is_same_ignore_cv.hpp"

namespace xte {
	template<typename T>
	concept is_number_or_bool = xte::is_number<T> || xte::is_same_ignore_cv<T, bool>;
}

#endif
