#ifndef DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_CONSTRUCTIBLE
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... arg_types>
	concept is_implicit_constructible =
		(sizeof...(arg_types) < 2)
		&& (sizeof...(arg_types)
			? requires ([:^^int(T):]& f) { f(xte::fake<arg_types...[0]>()); }
			: requires ([:^^int(T):]& f) { f({}); });
}

#endif
