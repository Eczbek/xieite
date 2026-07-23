#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CV_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CV_FUNC
#
#	include "../trait/copy_const_func.hpp"
#	include "../trait/copy_volatile_func.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_cv_func = xte::copy_volatile_func<T, xte::copy_const_func<T, U>>;
}

#endif
