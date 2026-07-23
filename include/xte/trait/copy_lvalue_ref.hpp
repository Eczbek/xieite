#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_LVALUE_REF
#
#	include "../trait/add_lvalue_ref.hpp"
#	include "../trait/drop_lvalue_ref.hpp"
#	include "../trait/is_lvalue_ref.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_lvalue_ref = [:xte::is_lvalue_ref<T> ? ^^xte::add_lvalue_ref<U> : ^^xte::drop_lvalue_ref<U>:];
}

#endif
