#ifndef DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_CTOR
#	define DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_CTOR
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... Args>
	concept is_implicit_ctor =
		(sizeof...(Args) < 2)
		&& (sizeof...(Args)
			? requires ([:^^int(T):]& f) {
				f(xte::fake<Args...[0]>());
			}
			: requires ([:^^int(T):]& f) {
				f({});
			});
}

#endif
