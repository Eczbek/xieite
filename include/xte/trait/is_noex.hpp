#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX
#
#	include "../trait/is_func.hpp"
#	include <meta>

namespace xte {
	template<typename func_type>
	concept is_noex = xte::is_func<func_type> && std::meta::is_noexcept(^^func_type);
}

#endif
