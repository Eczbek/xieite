#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CREF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CREF
#
#	include "../trait/copy_c.hpp"
#	include "../trait/copy_ref.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_cref = xte::copy_ref<T, xte::copy_c<T, U>>;
}

#endif
