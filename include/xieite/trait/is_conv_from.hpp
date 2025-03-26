#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CONV_FROM
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CONV_FROM
#
#	include <concepts>

namespace xieite {
	template<typename T, typename... Us>
	concept is_conv_from = (... && std::convertible_to<Us, T>);
}

#endif
