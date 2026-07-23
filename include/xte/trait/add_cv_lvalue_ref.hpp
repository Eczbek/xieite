#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_CV_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_ADD_CV_LVALUE_REF
#
#	include "../trait/add_cv.hpp"
#	include "../trait/add_lvalue_ref.hpp"

namespace xte {
	template<typename T>
	using add_cv_lvalue_ref = xte::add_lvalue_ref<xte::add_cv<T>>;
}

#endif
