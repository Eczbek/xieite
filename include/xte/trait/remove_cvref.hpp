#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_CVREF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_CVREF
#
#	include "../trait/remove_cv.hpp"
#	include "../trait/remove_ref.hpp"

namespace xte {
	template<typename T>
	using remove_cvref = xte::remove_ref<xte::remove_cv<T>>;
}

#endif
