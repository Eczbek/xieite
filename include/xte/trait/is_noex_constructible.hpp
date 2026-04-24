#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_CONSTRUCTIBLE
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... Args>
	concept is_noex_constructible =
		((sizeof...(Args) == 1)
			? requires { { static_cast<T>(xte::fake<Args...[0]>()) } noexcept; }
			: requires { { T(xte::fake<Args>()...) } noexcept; });
}

#endif
