#ifndef DETAIL_XTE_HEADER_TRAIT_IS_MOVE_CTOR
#	define DETAIL_XTE_HEADER_TRAIT_IS_MOVE_CTOR
#
#	include "../trait/is_ctor.hpp"
#	include "../trait/remove_ref.hpp"

namespace xte {
	template<typename T>
	concept is_move_ctor = xte::is_ctor<T, xte::remove_ref<T>>;
}

#endif
