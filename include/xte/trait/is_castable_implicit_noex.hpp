#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CASTABLE_IMPLICIT_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_CASTABLE_IMPLICIT_NOEX
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_castable_implicit_noex = requires ([:^^int(U) noexcept:]& f) { { f(xte::fake<T>()) } noexcept; };
}

#endif
