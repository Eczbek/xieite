#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_VOLATILE_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_VOLATILE_LVALUE_REF
#
#	include "../trait/copy_lvalue_ref.hpp"
#	include "../trait/copy_volatile.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_volatile_lvalue_ref = xte::copy_lvalue_ref<T, xte::copy_volatile<T, U>>;
}

#endif
