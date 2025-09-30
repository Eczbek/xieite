#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NONE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NONE
#
#	include "../trait/is_any.hpp"

namespace xte {
	template<typename T, auto... predicates>
	concept is_none = not xte::is_any<T, predicates...>;
}

#endif
