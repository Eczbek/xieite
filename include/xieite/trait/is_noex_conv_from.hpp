#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_CONV_FROM
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_CONV_FROM
#
#	include "../trait/is_noex_conv.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_noex_conv_from = (... && xieite::is_noex_conv<Us, T>);
}

#endif
