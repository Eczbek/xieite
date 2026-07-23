#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CV_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CV_RVALUE_REF
#
#	include "../trait/drop_cv.hpp"
#	include "../trait/drop_rvalue_ref.hpp"

namespace xte {
	template<typename T>
	using drop_cv_rvalue_ref = xte::drop_rvalue_ref<xte::drop_cv<T>>;
}

#endif
