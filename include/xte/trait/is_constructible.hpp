#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_CONSTRUCTIBLE
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... arg_types>
	concept is_constructible =
		((sizeof...(arg_types) == 1)
			? requires { static_cast<T>(xte::fake<arg_types...[0]>()); }
			: requires { T(xte::fake<arg_types>()...); });
}

#endif
