#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_VOLATILE_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_VOLATILE_LVALUE_REF
#
#	include "../trait/drop_lvalue_ref.hpp"
#	include "../trait/drop_volatile.hpp"

namespace xte {
	template<typename T>
	using drop_volatile_lvalue_ref = xte::drop_lvalue_ref<xte::drop_volatile<T>>;
}

#endif
