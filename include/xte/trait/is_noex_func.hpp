#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_FUNC
#
#	include "../trait/is_func.hpp"
#	include <meta>

namespace xte {
	template<typename func_type>
	concept is_noex_func = xte::is_func<func_type> && std::meta::is_noexcept(^^func_type);
}

#endif
