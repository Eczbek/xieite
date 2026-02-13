#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_REF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_REF
#
#	include "../trait/add_ptr.hpp"

namespace xte {
	template<typename T>
	using remove_ref = xte::add_ptr<T, 0>;
}

#endif
