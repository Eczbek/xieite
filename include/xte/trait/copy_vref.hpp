#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_VREF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_VREF
#
#	include "../trait/copy_ref.hpp"
#	include "../trait/copy_v.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_vref = xte::copy_ref<T, xte::copy_v<T, U>>;
}

#endif
