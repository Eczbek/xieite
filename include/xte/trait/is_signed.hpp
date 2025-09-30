#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SIGNED
#	define DETAIL_XTE_HEADER_TRAIT_IS_SIGNED
#
#	include "../trait/is_same_any_unqual.hpp"

namespace xte {
	template<typename T>
	concept is_signed = xte::is_same_any_unqual<T, signed char, short, int, long, long long>;
}

#endif
