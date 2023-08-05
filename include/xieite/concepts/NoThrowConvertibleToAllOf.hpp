#ifndef XIEITE_HEADER__CONCEPTS__NO_THROW_CONVERTIBLE_TO_ALL_OF
#	define XIEITE_HEADER__CONCEPTS__NO_THROW_CONVERTIBLE_TO_ALL_OF

#	include "../traits/IsNoThrowConvertibleToAllOf.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToAllOf = xieite::traits::IsNoThrowConvertibleToAllOf<Source, Targets...>::value;
}

#endif
