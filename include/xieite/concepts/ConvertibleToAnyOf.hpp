#ifndef XIEITE_HEADER__CONCEPTS__CONVERTIBLE_TO_ANY_OF
#	define XIEITE_HEADER__CONCEPTS__CONVERTIBLE_TO_ANY_OF

#	include "../traits/IsConvertibleToAnyOf.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept ConvertibleToAnyOf = xieite::traits::IsConvertibleToAnyOf<Source, Targets...>::value;
}

#endif
