#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CONV_TO_ANY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CONV_TO_ANY
#
#	include "../trait/is_conv_to.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_conv_to_any = (... || xieite::is_conv_to<T, Us>);
}

#endif
