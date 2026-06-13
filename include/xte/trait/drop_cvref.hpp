#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CVREF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CVREF
#
#	include "../trait/drop_cv.hpp"
#	include "../trait/drop_ref.hpp"

namespace xte {
	template<typename T>
	using drop_cvref = xte::drop_ref<xte::drop_cv<T>>;
}

#endif
