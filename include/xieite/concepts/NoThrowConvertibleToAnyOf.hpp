#ifndef XIEITE_HEADER__CONCEPTS__NO_THROW_CONVERTIBLE_TO_ANY_OF
#	define XIEITE_HEADER__CONCEPTS__NO_THROW_CONVERTIBLE_TO_ANY_OF

#	include "../concepts/NoThrowConvertibleTo.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToAnyOf = (... || xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
}

#endif
