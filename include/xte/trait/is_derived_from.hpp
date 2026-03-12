#ifndef DETAIL_XTE_HEADER_TRAIT_IS_DERIVED_FROM
#	define DETAIL_XTE_HEADER_TRAIT_IS_DERIVED_FROM
#
#	include "../trait/is_castable.hpp"
#	include "../trait/remove_cvref.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_derived_from = xte::is_castable<xte::remove_cvref<T>*, xte::remove_cvref<U>*>;
}

#endif
