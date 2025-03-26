#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CONV_TO
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CONV_TO
#
#	include <concepts>

namespace xieite {
	template<typename T, typename... Us>
	concept is_conv_to = (... && std::convertible_to<T, Us>);
}

#endif
