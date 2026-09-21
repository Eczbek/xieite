#ifndef DETAIL_XTE_HEADER_TRAIT_IS_INT
#	define DETAIL_XTE_HEADER_TRAIT_IS_INT
#
#	include "../trait/is_signed_int.hpp"
#	include "../trait/is_unsigned_int.hpp"

namespace xte {
	template<typename T>
	concept is_int = xte::is_unsigned_int<T> || xte::is_signed_int<T>;
}

#endif
