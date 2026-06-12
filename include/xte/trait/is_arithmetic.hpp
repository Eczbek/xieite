#ifndef DETAIL_XTE_HEADER_TRAIT_IS_ARITHMETIC
#	define DETAIL_XTE_HEADER_TRAIT_IS_ARITHMETIC
#
#	include "../trait/is_float.hpp"
#	include "../trait/is_int.hpp"

namespace xte {
	template<typename T>
	concept is_arithmetic = xte::is_int<T> || xte::is_float<T>;
}

#endif
