#ifndef XIEITE_HEADER_TRAITS_IS_CONVERTIBLE_TO_ALL
#	define XIEITE_HEADER_TRAITS_IS_CONVERTIBLE_TO_ALL

#	include <type_traits>
#	include "../concepts/convertible_to_all.hpp"

namespace xieite::traits {
	template<typename Source_, typename... Targets_>
	struct IsConvertibleToAll
	: std::bool_constant<xieite::concepts::ConvertibleToAll<Source_, Targets_...>> {};
}

#endif
