#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_CV_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_ADD_CV_FUNC
#
#	include "../trait/add_const_func.hpp"
#	include "../trait/add_volatile_func.hpp"

namespace xte {
	template<typename T>
	using add_cv_func = xte::add_volatile_func<xte::add_const_func<T>>;
}

#endif
