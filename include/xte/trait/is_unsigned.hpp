#ifndef DETAIL_XTE_HEADER_TRAIT_IS_UNSIGNED
#	define DETAIL_XTE_HEADER_TRAIT_IS_UNSIGNED
#
#	include "../preproc/feature.hpp"
#	include "../trait/is_same_any_ignore_cv.hpp"
#	include "../util/types.hpp"

namespace xte {
	template<typename T>
	concept is_unsigned = xte::is_same_any_ignore_cv<T,
		unsigned char,
		unsigned short,
		unsigned int,
		unsigned long,
		unsigned long long
#	if XTE_FEATURE_INT_128
		, xte::u128
#	endif
	>;
}

#endif
