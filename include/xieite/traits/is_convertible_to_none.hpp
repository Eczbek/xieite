#ifndef XIEITE_HEADER_TRAITS_IS_CONVERTIBLE_TO_NONE
#	define XIEITE_HEADER_TRAITS_IS_CONVERTIBLE_TO_NONE

#	include <type_traits>
#	include "../concepts/convertible_to_none.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsConvertibleToNone
	: std::bool_constant<xieite::concepts::ConvertibleToNone<Source, Targets...>> {};
}

#endif
