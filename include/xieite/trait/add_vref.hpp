#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VREF
#
#	include "../trait/add_ref.hpp"
#	include "../trait/add_v.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_vref = xieite::add_v<xieite::add_ref<T, U>>;
}

#endif
