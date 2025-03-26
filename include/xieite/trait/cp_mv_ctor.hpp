#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_MV_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_MV_CTOR
#
#	include <type_traits>
#	include "../trait/set_mv_ctor.hpp"

namespace xieite {
	template<typename T>
	using cp_mv_ctor = xieite::set_mv_ctor<std::is_move_constructible_v<T>>;
}

#endif
