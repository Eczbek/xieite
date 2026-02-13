#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_VRREF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_VRREF
#
#	include "../trait/copy_rref.hpp"
#	include "../trait/copy_v.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_vrref = xte::copy_rref<T, xte::copy_v<T, U>>;
}

#endif
