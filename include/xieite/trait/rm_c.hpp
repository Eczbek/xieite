#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_C
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_C
#
#	include <type_traits>
#	include "../trait/cp_ref.hpp"
#	include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using rm_c = xieite::cp_ref<T, std::remove_const_t<xieite::rm_ref<T>>>;
}

#endif
