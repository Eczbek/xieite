#ifndef XIEITE_HEADER_TRAITS_IS_NO_THROW_CONVERTIBLE_TO_ALL
#	define XIEITE_HEADER_TRAITS_IS_NO_THROW_CONVERTIBLE_TO_ALL

#	include <type_traits>
#	include "../concepts/no_throw_convertible_to_all.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsNoThrowConvertibleToAll
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToAll<Source, Targets...>> {};
}

#endif
