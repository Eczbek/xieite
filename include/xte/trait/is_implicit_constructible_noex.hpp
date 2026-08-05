#ifndef DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_CONSTRUCTIBLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_CONSTRUCTIBLE_NOEX
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... arg_types>
	concept is_implicit_constructible_noex = 
		(sizeof...(arg_types) < 2)
		&& (sizeof...(arg_types)
			? requires ([:^^int(T) noexcept:]& f) { { f(xte::fake<arg_types...[0]>()) } noexcept; }
			: requires ([:^^int(T) noexcept:]& f) { { f({}) } noexcept; });
}

#endif
