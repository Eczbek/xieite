#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_C
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_C
#
#	include "../trait/cp_ref.hpp"
#	include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using add_c = xieite::cp_ref<T, const xieite::rm_ref<T>>;
}

#endif
