#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_ARRAY
#	define DETAIL_XTE_HEADER_TRAIT_ADD_ARRAY
#
#	include "../util/numbers.hpp"

namespace xte {
	template<typename T, xte::uz size>
	using add_array = T[size];
}

#endif
