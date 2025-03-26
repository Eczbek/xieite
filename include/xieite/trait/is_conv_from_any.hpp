#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CONV_FROM_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CONV_FROM_ANY
#
#	include "../trait/is_conv_from.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_conv_from_any = (... || xieite::is_conv_from<T, Us>);
}

#endif
