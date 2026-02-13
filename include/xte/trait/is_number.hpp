#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NUMBER
#	define DETAIL_XTE_HEADER_TRAIT_IS_NUMBER
#
#	include "../trait/is_float.hpp"
#	include "../trait/is_int.hpp"

namespace xte {
	template<typename T>
	concept is_number = xte::is_int<T> || xte::is_float<T>;
}

#endif
