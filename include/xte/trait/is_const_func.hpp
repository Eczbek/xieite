#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CONST_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_CONST_FUNC
#
#	include "../trait/is_func.hpp"
#	include <meta>

namespace xte {
	template<typename func_type>
	concept is_const_func = xte::is_func<func_type> && std::meta::is_const(^^func_type);
}

#endif
