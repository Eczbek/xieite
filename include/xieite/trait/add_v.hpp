#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_V
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_V
#
#	include "../trait/cp_ref.hpp"
#	include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using add_v = xieite::cp_ref<T, volatile xieite::rm_ref<T>>;
}

#endif
