#ifndef XIEITE_HEADER__TRAITS___NO_THROW_CONVERTIBLE_TO_NONE
#	define XIEITE_HEADER__TRAITS___NO_THROW_CONVERTIBLE_TO_NONE

#	include <type_traits>
#	include "../concepts/no_throw_convertible_to_none.hpp"

namespace xieite::traits {
	template<typename Source, typename... Targets>
	struct NoThrowConvertibleToNone
	: std::bool_constant<xieite::concepts::NoThrowConvertibleToNone<Source, Targets...>> {};
}

#endif
