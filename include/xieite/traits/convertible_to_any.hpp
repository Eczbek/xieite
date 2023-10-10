#ifndef XIEITE_HEADER__TRAITS___CONVERTIBLE_TO_ANY
#	define XIEITE_HEADER__TRAITS___CONVERTIBLE_TO_ANY

#	include <type_traits>
#	include "../concepts/convertible_to_any.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct ConvertibleToAny
	: std::bool_constant<xieite::concepts::ConvertibleToAny<Source, Targets...>> {};
}

#endif
