#ifndef XIEITE_HEADER_TRAITS_IS_NO_THROW_CONVERTIBLE_TO_NONE
#	define XIEITE_HEADER_TRAITS_IS_NO_THROW_CONVERTIBLE_TO_NONE

#	include <type_traits>
#	include "../concepts/no_throw_convertible_to_none.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsNoThrowConvertibleToNone
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToNone<Source, Targets...>> {};
}

#endif
