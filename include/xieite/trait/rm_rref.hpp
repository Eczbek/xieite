#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_RREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_RREF
#
#	include <type_traits>
#	include "../trait/is_rref.hpp"
#	include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using rm_rref = std::conditional_t<xieite::is_rref<T>, xieite::rm_ref<T>, T>;
}

#endif
