#ifndef DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_CASTABLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_CASTABLE_NOEX
#
#	include "../meta/fake.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_implicit_castable_noex = requires ([:^^int(U) noexcept:]& f) { { f(xte::fake<T>()) } noexcept; };
}

#endif
