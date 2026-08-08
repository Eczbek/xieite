#ifndef DETAIL_XTE_HEADER_TRAIT_IS_COPY_CONSTRUCTIBLE_IMPLICIT
#	define DETAIL_XTE_HEADER_TRAIT_IS_COPY_CONSTRUCTIBLE_IMPLICIT
#
#	include "../trait/add_const_lvalue_ref.hpp"
#	include "../trait/is_constructible_implicit.hpp"

namespace xte {
	template<typename T>
	concept is_copy_constructible_implicit = xte::is_constructible_implicit<T, xte::add_const_lvalue_ref<T>>;
}

#endif
