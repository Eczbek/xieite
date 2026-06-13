#ifndef DETAIL_XTE_HEADER_TRAIT_IS_DERIVED_FROM
#	define DETAIL_XTE_HEADER_TRAIT_IS_DERIVED_FROM
#
#	include "../trait/drop_cvref.hpp"
#	include "../trait/is_castable.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_derived_from = xte::is_castable<xte::drop_cvref<T>*, xte::drop_cvref<U>*>;
}

#endif
