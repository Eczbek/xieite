#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_ASSIGNABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_ASSIGNABLE
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_noex_assignable = requires { { xte::fake<T>() = xte::fake<U>() } noexcept; };
}

#endif
