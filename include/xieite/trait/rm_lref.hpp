#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_LREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_LREF
#
#	include <type_traits>
#	include "../trait/is_lref.hpp"
#	include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using rm_lref = std::conditional_t<xieite::is_lref<T>, xieite::rm_ref<T>, T>;
}

#endif
