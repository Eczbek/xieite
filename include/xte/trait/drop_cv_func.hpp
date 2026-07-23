#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CV_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CV_FUNC
#
#	include "../trait/drop_const_func.hpp"
#	include "../trait/drop_volatile_func.hpp"

namespace xte {
	template<typename T>
	using drop_cv_func = xte::drop_volatile_func<xte::drop_const_func<T>>;
}

#endif
