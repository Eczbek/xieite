#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CONSTRUCTIBLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_CONSTRUCTIBLE_NOEX
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... arg_types>
	concept is_constructible_noex =
		((sizeof...(arg_types) == 1)
			? requires { { static_cast<T>(xte::fake<arg_types...[0]>()) } noexcept; }
			: requires { { T(xte::fake<arg_types>()...) } noexcept; });
}

#endif
