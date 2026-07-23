#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CREF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CREF
#
#	include "../trait/drop_const.hpp"
#	include "../trait/drop_ref.hpp"

namespace xte {
	template<typename T>
	using drop_cref = xte::drop_ref<xte::drop_const<T>>;
}

#endif
