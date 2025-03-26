#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_TRIVIAL_MV_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_TRIVIAL_MV_CTOR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept has_trivial_mv_ctor = std::is_trivially_move_constructible_v<T>;
}

#endif
