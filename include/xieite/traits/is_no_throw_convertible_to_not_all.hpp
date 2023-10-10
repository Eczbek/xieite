#ifndef XIEITE_HEADER__TRAITS__IS_NO_THROW_CONVERTIBLE_TO_NOT_ALL
#	define XIEITE_HEADER__TRAITS__IS_NO_THROW_CONVERTIBLE_TO_NOT_ALL

#	include <type_traits>
#	include "../concepts/no_throw_convertible_to_not_all.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct IsNoThrowConvertibleToNotAll
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToNotAll<Source, Targets...>> {};
}

#endif
