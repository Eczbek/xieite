#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY_UNQUAL
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY_UNQUAL
#
#	include "../trait/is_same_unqual.hpp"

namespace xte {
	template<typename T, typename... Us>
	concept is_same_any_unqual = (... || xte::is_same_unqual<T, Us>);
}

#endif
