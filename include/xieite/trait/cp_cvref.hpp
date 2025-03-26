#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_CVREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_CVREF
#
#	include "../trait/cp_cv.hpp"
#	include "../trait/cp_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cvref = xieite::cp_cv<T, xieite::cp_ref<T, U>>;
}

#endif
