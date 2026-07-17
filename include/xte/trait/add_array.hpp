#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_ARRAY
#	define DETAIL_XTE_HEADER_TRAIT_ADD_ARRAY
#
#	include "../util/number_types.hpp"

namespace xte {
	template<typename T, xte::uz size>
	requires(size > 0)
	using add_array = T[size];
}

#endif
