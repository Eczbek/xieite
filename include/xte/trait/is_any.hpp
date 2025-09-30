#ifndef DETAIL_XTE_HEADER_TRAIT_IS_ANY
#	define DETAIL_XTE_HEADER_TRAIT_IS_ANY
#
#	include "../trait/is.hpp"

namespace xte {
	template<typename T, auto... predicates>
	concept is_any = (... || xte::is<T, predicates>);
}

#endif
