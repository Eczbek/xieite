#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CVRREF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CVRREF
#
#	include "../trait/copy_cv.hpp"
#	include "../trait/copy_rref.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_cvrref = xte::copy_rref<T, xte::copy_cv<T, U>>;
}

#endif
