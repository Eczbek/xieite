#ifndef DETAIL_XTE_HEADER_TRAIT_HAS_IMPLICIT_CTOR
#	define DETAIL_XTE_HEADER_TRAIT_HAS_IMPLICIT_CTOR
#
#	include "../meta/declare.hpp"
#	include "../meta/type.hpp"

namespace xte {
	template<typename T, typename... Args>
	concept has_implicit_ctor =
		(sizeof...(Args) < 2)
		&& (sizeof...(Args)
			? requires (xte::type<int(T)>& f) {
				f(xte::declare<Args...[0]>());
			}
			: requires (xte::type<int(T)>& f) {
				f({});
			});
}

#endif
