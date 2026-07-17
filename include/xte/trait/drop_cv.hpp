#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CV
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CV
#
#	include "../trait/drop_const.hpp"
#	include "../trait/drop_volatile.hpp"

namespace xte {
	template<typename T>
	using drop_cv = xte::drop_volatile<xte::drop_const<T>>;
}

#endif
