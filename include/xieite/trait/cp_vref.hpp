#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VREF
#
#	include "../trait/cp_v.hpp"
#	include "../trait/cp_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_vref = xieite::cp_v<T, xieite::cp_ref<T, U>>;
}

#endif
