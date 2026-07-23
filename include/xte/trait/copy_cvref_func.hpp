#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CVREF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CVREF_FUNC
#
#	include "../trait/copy_cv_func.hpp"
#	include "../trait/copy_ref_func.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_cvref_func = xte::copy_ref_func<T, xte::copy_cv_func<T, U>>;
}

#endif
