#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_CP_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_CP_CTOR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept has_cp_ctor = std::is_copy_constructible_v<T>;
}

#endif
