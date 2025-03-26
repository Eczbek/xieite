#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_NOEX_CP_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_NOEX_CP_CTOR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept has_noex_cp_ctor = std::is_nothrow_copy_constructible_v<T>;
}

#endif
