#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VARIADIC_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_VARIADIC_FUNC
#
#	include "../trait/is_func.hpp"
#	include <meta>

namespace xte {
	template<typename func_type>
	concept is_variadic_func = xte::is_func<func_type> && std::meta::is_volatile(^^func_type);
}

#endif
