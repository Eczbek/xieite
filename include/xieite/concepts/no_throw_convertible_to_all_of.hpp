#ifndef XIEITE_HEADER__CONCEPTS__NO_THROW_CONVERTIBLE_TO_ALL_OF
#	define XIEITE_HEADER__CONCEPTS__NO_THROW_CONVERTIBLE_TO_ALL_OF

#	include "../concepts/no_throw_convertible_to.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToAllOf = (... && xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
}

#endif
