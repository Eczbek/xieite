#ifndef XIEITE_HEADER_TRAITS_NO_THROW_CONVERTIBLE_TO_NOT_ALL
#	define XIEITE_HEADER_TRAITS_NO_THROW_CONVERTIBLE_TO_NOT_ALL

#	include <type_traits>
#	include "../concepts/no_throw_convertible_to_not_all.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct NoThrowConvertibleToNotAll
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToNotAll<Source, Targets...>> {};
}

#endif
