#ifndef DETAIL_XTE_HEADER_TRAIT_IS_UNSIGNED
#	define DETAIL_XTE_HEADER_TRAIT_IS_UNSIGNED
#
#	include "../trait/is_same_any_unqual.hpp"

namespace xte {
	template<typename T>
	concept is_unsigned = xte::is_same_any_unqual<T, unsigned char, unsigned short, unsigned int, unsigned long, unsigned long long>;
}

#endif
