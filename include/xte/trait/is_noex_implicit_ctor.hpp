#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_IMPLICIT_CTOR
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_IMPLICIT_CTOR
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... Args>
	concept is_noex_implicit_ctor = 
		(sizeof...(Args) < 2)
		&& (sizeof...(Args)
			? requires { { xte::fake<int(&)(T) noexcept>()(xte::fake<Args...[0]>()) } noexcept; }
			: requires { { xte::fake<int(&)(T) noexcept>()({}) } noexcept; });
}

#endif
