#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CV
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CV
#
#	include "../trait/copy_const.hpp"
#	include "../trait/copy_volatile.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_cv = xte::copy_volatile<T, xte::copy_const<T, U>>;
}

#endif
