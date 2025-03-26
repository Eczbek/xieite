#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_V
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_V
#
#	include <type_traits>
#	include "../trait/cp_ref.hpp"
#	include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using rm_v = xieite::cp_ref<T, std::remove_volatile_t<xieite::rm_ref<T>>>;
}

#endif
