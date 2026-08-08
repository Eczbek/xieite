#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CONSTRUCTIBLE_IMPLICIT_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_CONSTRUCTIBLE_IMPLICIT_NOEX
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... arg_types>
	concept is_constructible_implicit_noex = 
		(sizeof...(arg_types) < 2)
		&& (sizeof...(arg_types)
			? requires ([:^^int(T) noexcept:]& f) { { f(xte::fake<arg_types...[0]>()) } noexcept; }
			: requires ([:^^int(T) noexcept:]& f) { { f({}) } noexcept; });
}

#endif
