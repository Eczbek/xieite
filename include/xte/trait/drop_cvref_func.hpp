#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CVREF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CVREF_FUNC
#
#	include "../trait/drop_cv_func.hpp"
#	include "../trait/drop_ref_func.hpp"

namespace xte {
	template<typename T>
	using drop_cvref_func = xte::drop_ref_func<xte::drop_cv_func<T>>;
}

#endif
