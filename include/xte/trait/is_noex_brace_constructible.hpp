#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_BRACE_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_BRACE_CONSTRUCTIBLE
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename... Args>
	concept is_noex_brace_constructible = requires { { T { xte::fake<Args>()... } } noexcept; };
}

#endif
