#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_VREF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_VREF
#
#	include "../trait/drop_ref.hpp"
#	include "../trait/drop_volatile.hpp"

namespace xte {
	template<typename T>
	using drop_vref = xte::drop_ref<xte::drop_volatile<T>>;
}

#endif
