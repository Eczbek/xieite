#ifndef XIEITE_HEADER__CONCEPTS__CONVERTIBLE_TO_ALL_OF
#	define XIEITE_HEADER__CONCEPTS__CONVERTIBLE_TO_ALL_OF

#	include "../traits/IsConvertibleToAllOf.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToAllOf = xieite::traits::IsConvertibleToAllOf<Source, Targets...>::value;
}

#endif
