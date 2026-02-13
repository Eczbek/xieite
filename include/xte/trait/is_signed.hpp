#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SIGNED
#	define DETAIL_XTE_HEADER_TRAIT_IS_SIGNED
#
#	include "../preproc/feature.hpp"
#	include "../trait/is_same_any_ignore_cv.hpp"
#	include "../util/types.hpp"

namespace xte {
	template<typename T>
	concept is_signed = xte::is_same_any_ignore_cv<T,
		signed char,
		short,
		int,
		long,
		long long
#	if XTE_FEATURE_INT_128
		, xte::i128
#	endif
	>;
}

#endif
