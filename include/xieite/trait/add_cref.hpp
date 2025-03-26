#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CREF
#
#	include "../trait/add_c.hpp"
#	include "../trait/add_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_cref = xieite::add_c<xieite::add_ref<T, U>>;
}

#endif
