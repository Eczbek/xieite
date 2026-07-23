#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_VOLATILE_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_VOLATILE_RVALUE_REF
#
#	include "../trait/drop_rvalue_ref.hpp"
#	include "../trait/drop_volatile.hpp"

namespace xte {
	template<typename T>
	using drop_volatile_rvalue_ref = xte::drop_rvalue_ref<xte::drop_volatile<T>>;
}

#endif
