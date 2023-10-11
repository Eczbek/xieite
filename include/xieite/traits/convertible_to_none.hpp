#ifndef XIEITE_HEADER_TRAITS_CONVERTIBLE_TO_NONE
#	define XIEITE_HEADER_TRAITS_CONVERTIBLE_TO_NONE

#	include <type_traits>
#	include "../concepts/convertible_to_none.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct ConvertibleToNone
	: std::bool_constant<xieite::concepts::ConvertibleToNone<Source, Targets...>> {};
}

#endif
