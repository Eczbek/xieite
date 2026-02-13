#ifndef DETAIL_XTE_HEADER_TRAIT_IS_PRIVATELY_DERIVED_FROM
#	define DETAIL_XTE_HEADER_TRAIT_IS_PRIVATELY_DERIVED_FROM
#
#	include "../meta/refl.hpp"
#	include "../trait/is_derived_from.hpp"
#	include "../trait/remove_cv.hpp"
#	include <algorithm>

namespace xte {
	template<typename T, typename U>
	concept is_privately_derived_from = !xte::is_derived_from<T, U> && std::ranges::contains(xte::refl::bases_of(^^T, std::meta::access_context::unchecked()), std::meta::dealias(^^xte::remove_cv<U>), xte::refl::type_of);
}

#endif
