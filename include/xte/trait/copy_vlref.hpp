#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_VLREF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_VLREF
#
#	include "../trait/copy_lref.hpp"
#	include "../trait/copy_v.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_vlref = xte::copy_lref<T, xte::copy_v<T, U>>;
}

#endif
