#ifndef DETAIL_XTE_HEADER_TRAIT_IS_ASSIGNABLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_ASSIGNABLE_NOEX
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_assignable_noex = requires { { xte::fake<T>() = xte::fake<U>() } noexcept; };
}

#endif
