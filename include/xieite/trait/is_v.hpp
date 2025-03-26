#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_V
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_V
#
#	include <type_traits>
#	include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	concept is_v = std::is_volatile_v<xieite::rm_ref<T>>;
}

#endif
