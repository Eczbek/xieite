#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_VREF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_COPY_VREF_FUNC
#
#	include "../trait/copy_ref_func.hpp"
#	include "../trait/copy_volatile_func.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_vref_func = xte::copy_ref_func<T, xte::copy_volatile_func<T, U>>;
}

#endif
