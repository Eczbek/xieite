#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CV_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CV_LVALUE_REF
#
#	include "../trait/drop_cv.hpp"
#	include "../trait/drop_lvalue_ref.hpp"

namespace xte {
	template<typename T>
	using drop_cv_lvalue_ref = xte::drop_lvalue_ref<xte::drop_cv<T>>;
}

#endif
