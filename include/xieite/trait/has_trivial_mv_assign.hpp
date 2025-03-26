#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_TRIVIAL_MV_ASSIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_TRIVIAL_MV_ASSIGN
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept has_trivial_mv_assign = std::is_trivially_move_assignable_v<T>;
}

#endif
