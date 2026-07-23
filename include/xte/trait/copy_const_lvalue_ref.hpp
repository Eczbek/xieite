#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CONST_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CONST_LVALUE_REF
#
#	include "../trait/copy_const.hpp"
#	include "../trait/copy_lvalue_ref.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_const_lvalue_ref = xte::copy_lvalue_ref<T, xte::copy_const<T, U>>;
}

#endif
