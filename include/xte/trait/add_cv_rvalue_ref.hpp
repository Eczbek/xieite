#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_CV_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_ADD_CV_RVALUE_REF
#
#	include "../trait/add_cv.hpp"
#	include "../trait/add_rvalue_ref.hpp"

namespace xte {
	template<typename T>
	using add_cv_rvalue_ref = xte::add_rvalue_ref<xte::add_cv<T>>;
}

#endif
