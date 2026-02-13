#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CV
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CV
#
#	include "../trait/copy_c.hpp"
#	include "../trait/copy_v.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_cv = xte::copy_v<T, xte::copy_c<T, U>>;
}

#endif
