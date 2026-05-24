#ifndef DETAIL_XTE_HEADER_TRAIT_IS_PRIVATELY_DERIVED_FROM
#	define DETAIL_XTE_HEADER_TRAIT_IS_PRIVATELY_DERIVED_FROM
#
#	include "../meta/meta.hpp"
#	include "../trait/is_derived_from.hpp"
#	include <algorithm>
#	include <meta>

namespace xte {
	template<typename T, typename U>
	concept is_privately_derived_from =
		!xte::is_derived_from<T, U>
		&& std::ranges::contains(
			xte::meta::bases_of(^^T, std::meta::access_context::unchecked()),
			std::meta::remove_cv(^^U),
			xte::meta::type_of
		);
}

#endif
