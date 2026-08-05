#ifndef DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_COPY_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_COPY_CONSTRUCTIBLE
#
#	include "../trait/add_const_lvalue_ref.hpp"
#	include "../trait/is_implicit_constructible.hpp"

namespace xte {
	template<typename T>
	concept is_implicit_copy_constructible = xte::is_implicit_constructible<T, xte::add_const_lvalue_ref<T>>;
}

#endif
