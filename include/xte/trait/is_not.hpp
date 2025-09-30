#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOT
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOT
#
#	include "../trait/is.hpp"

namespace xte {
	template<typename T, auto... predicates>
	concept is_not = not xte::is<T, predicates...>;
}

#endif
