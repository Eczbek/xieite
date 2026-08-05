#ifndef DETAIL_XTE_HEADER_TRAIT_IS_BRACE_CONSTRUCTIBLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_BRACE_CONSTRUCTIBLE_NOEX
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... arg_types>
	concept is_brace_constructible_noex = requires { { T { xte::fake<arg_types>()... } } noexcept; };
}

#endif
