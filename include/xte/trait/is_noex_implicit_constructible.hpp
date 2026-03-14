#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_IMPLICIT_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_IMPLICIT_CONSTRUCTIBLE
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... Args>
	concept is_noex_implicit_constructible = 
		(sizeof...(Args) < 2)
		&& (sizeof...(Args)
			? requires ([:^^int(T) noexcept:]& f) { { f(xte::fake<Args...[0]>()) } noexcept; }
			: requires ([:^^int(T) noexcept:]& f) { { f({}) } noexcept; });
}

#endif
