#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_REF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_REF
#
#	include "../trait/add_ptr.hpp"

namespace xte {
	template<typename T>
	using drop_ref = xte::add_ptr<T, 0>;
}

#endif
