#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_CONV_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_CONV_ANY
#
#	include "../trait/is_noex_conv.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_noex_conv_any = (... || xieite::is_noex_conv<T, Us>);
}

#endif
