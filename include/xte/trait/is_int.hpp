#ifndef DETAIL_XTE_HEADER_TRAIT_IS_INT
#	define DETAIL_XTE_HEADER_TRAIT_IS_INT
#
#	include "../trait/is_signed.hpp"
#	include "../trait/is_unsigned.hpp"

namespace xte {
	template<typename T>
	concept is_int = xte::is_unsigned<T> || xte::is_signed<T>;
}

#endif
