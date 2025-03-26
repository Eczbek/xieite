#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_MV_ASSIGN
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_MV_ASSIGN
#
#	include <type_traits>
#	include "../trait/set_mv_assign.hpp"

namespace xieite {
	template<typename T>
	using cp_mv_assign = xieite::set_mv_assign<std::is_move_assignable_v<T>>;
}

#endif
