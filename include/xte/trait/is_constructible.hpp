#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_CONSTRUCTIBLE
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename target_type, typename... arg_types>
	concept is_constructible =
		((sizeof...(arg_types) == 1)
			? requires { static_cast<target_type>(xte::fake<arg_types...[0]>()); }
			: requires { target_type(xte::fake<arg_types>()...); });
}

#endif
