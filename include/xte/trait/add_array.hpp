#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_ARRAY
#	define DETAIL_XTE_HEADER_TRAIT_ADD_ARRAY
#
#	include "../aliases.hpp"

namespace xte {
	template<typename T, xte::uz size>
	requires(size > 0)
	using add_array = T[size];
}

#endif
