#ifndef DETAIL_XTE_HEADER_TRAIT_IS_COPY_CONSTRUCTIBLE_IMPLICIT_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_COPY_CONSTRUCTIBLE_IMPLICIT_NOEX
#
#	include "../trait/add_const_lvalue_ref.hpp"
#	include "../trait/is_constructible_implicit_noex.hpp"

namespace xte {
	template<typename T>
	concept is_copy_constructible_implicit_noex = xte::is_constructible_implicit_noex<T, xte::add_const_lvalue_ref<T>>;
}

#endif
