#ifndef XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO_ANY
#	define XIEITE_HEADER_CONCEPTS_NO_THROW_CONVERTIBLE_TO_ANY

#	include "../concepts/no_throw_convertible_to.hpp"

namespace xieite::concepts {
	template<typename Source, typename... Targets>
	concept NoThrowConvertibleToAny = (... || xieite::concepts::NoThrowConvertibleTo<Source, Targets>);
}

#endif
