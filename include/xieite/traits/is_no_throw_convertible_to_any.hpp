#ifndef XIEITE_HEADER_TRAITS_IS_NO_THROW_CONVERTIBLE_TO_ANY
#	define XIEITE_HEADER_TRAITS_IS_NO_THROW_CONVERTIBLE_TO_ANY

#	include <type_traits>
#	include "../concepts/no_throw_convertible_to_any.hpp"

namespace xieite::traits {
	template<typename Source_, typename... Targets_>
	struct IsNoThrowConvertibleToAny
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToAny<Source_, Targets_...>> {};
}

#endif
