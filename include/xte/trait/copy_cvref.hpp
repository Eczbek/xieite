#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CVREF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CVREF
#
#	include "../trait/copy_cv.hpp"
#	include "../trait/copy_ref.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_cvref = xte::copy_ref<T, xte::copy_cv<T, U>>;
}

#endif
