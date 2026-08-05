#ifndef DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_COPY_CONSTRUCTIBLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_COPY_CONSTRUCTIBLE_NOEX
#
#	include "../trait/add_const_lvalue_ref.hpp"
#	include "../trait/is_implicit_constructible_noex.hpp"

namespace xte {
	template<typename T>
	concept is_implicit_copy_constructible_noex = xte::is_implicit_constructible_noex<T, xte::add_const_lvalue_ref<T>>;
}

#endif
