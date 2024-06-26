#ifndef XIEITE_HEADER_TRAITS_IS_CONVERTIBLE_TO_ANY
#	define XIEITE_HEADER_TRAITS_IS_CONVERTIBLE_TO_ANY

#	include <type_traits>
#	include "../concepts/convertible_to_any.hpp"

namespace xieite::traits {
	template<typename Source_, typename... Targets_>
	struct IsConvertibleToAny
	: std::bool_constant<xieite::concepts::ConvertibleToAny<Source_, Targets_...>> {};
}

#endif
