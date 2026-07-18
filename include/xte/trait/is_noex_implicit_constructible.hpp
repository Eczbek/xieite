#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_IMPLICIT_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_IMPLICIT_CONSTRUCTIBLE
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... arg_types>
	concept is_noex_implicit_constructible = 
		(sizeof...(arg_types) < 2)
		&& (sizeof...(arg_types)
			? requires ([:^^int(T) noexcept:]& f) { { f(xte::fake<arg_types...[0]>()) } noexcept; }
			: requires ([:^^int(T) noexcept:]& f) { { f({}) } noexcept; });
}

#endif
